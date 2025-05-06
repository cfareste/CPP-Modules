#include "BitcoinExchange.hpp"
#include <limits>
#include <cstdlib>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &databasePath)
{
	this->loadDatabase(databasePath);

	if (this->_database_values.empty())
		throw std::runtime_error("database is empty.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;

	this->_database_values = other._database_values;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool	BitcoinExchange::openFileForRead(const std::string &path, std::ifstream &fileStream)
{
	fileStream.open(path.c_str(), std::ios::in);

	return fileStream.is_open();
}

bool	BitcoinExchange::isFloat(const std::string &str)
{
	float				num;
	std::istringstream	stream(str);

	stream >> std::noskipws >> num;
	return stream.eof() && !stream.fail();
}

bool	BitcoinExchange::areValidDateValues(const std::string &year, const std::string &month, const std::string &day)
{
	long	yearValue = std::atol(year.c_str());
	long	monthValue = std::atol(month.c_str());
	long	dayValue = std::atol(day.c_str());

	return (yearValue >= 0 && yearValue <= 9999
			&& monthValue >= 1 && monthValue <= 12
			&& dayValue >= 1 && dayValue <= 31
			&& !(monthValue == 2 && dayValue > 29));
}

void	BitcoinExchange::checkDate(const std::string &date)
{
	std::size_t	firstDash = date.find('-');
	std::size_t	lastDash = date.rfind('-');
	std::string	year = date.substr(0, firstDash);
	std::string	month = date.substr(firstDash + 1, lastDash - firstDash - 1);
	std::string	day = date.substr(lastDash + 1);

	for (std::size_t i = 0; i < date.length(); i++)
	{
		if (date[i] != '-' && !std::isdigit(date[i]))
			throw std::invalid_argument("bad input => '" + date + "'");
	}
	if (!BitcoinExchange::areValidDateValues(year, month, day)
		|| year.length() != 4 || month.length() != 2 || day.length() != 2
		|| date.length() != 10)
		throw std::invalid_argument("bad input => '" + date + "'");
}

void	BitcoinExchange::checkValue(const std::string &value, float maxValue)
{
	if (!isFloat(value))
		throw std::invalid_argument("bad input => '" + value + "'");

	float	num = std::atof(value.c_str());
	if (num < 0)
		throw std::invalid_argument("not a positive number.");
	if (num > maxValue)
		throw std::invalid_argument("too large a number.");
}

void	BitcoinExchange::checkFormat(const std::string &key, const std::string &value, float maxValue)
{
	checkDate(key);
	checkValue(value, maxValue);
}

void	BitcoinExchange::loadDatabase(const std::string &databasePath)
{
	std::ifstream	databaseStream;
	std::string		key;
	std::string		line;
	std::string		value;

	if (!openFileForRead(databasePath, databaseStream))
		throw std::runtime_error("could not open file.");

	getline(databaseStream, line);
	if (line != DATABASE_HEADER)
		throw std::runtime_error("wrong database header.");
	while (getline(databaseStream, line))
	{
		key = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		checkFormat(key, value, std::numeric_limits<int>::max());
		this->_database_values[key] = std::atof(value.c_str());
	}
	databaseStream.close();
}

std::string	BitcoinExchange::getClosestKey(const std::string &key)
{
	if (this->_database_values.find(key) != this->_database_values.end())
		return key;
	if (key < this->_database_values.begin()->first)
		return NO_KEY_FOUND;

	std::map<std::string, float>::iterator			upperKeyIt = this->_database_values.upper_bound(key);
	const std::map<std::string, float>::iterator	closestKeyIt = --upperKeyIt;
	return closestKeyIt->first;
}

float	BitcoinExchange::calculateDatePrice(const std::string &date, const std::string &amount)
{
	if (date.empty() || amount.empty())
		throw std::invalid_argument("bad input => '" + date + " | " + amount + "'");

	std::string	key = getClosestKey(date);
	if (key == NO_KEY_FOUND)
		throw std::invalid_argument("no date available to calculate price => '" + date + "'");

	return this->_database_values.at(key) * static_cast<float>(std::atof(amount.c_str()));
}

void	BitcoinExchange::calculatePricesFromFile(const std::string &filePath)
{
	std::ifstream	fileStream;
	std::string		key;
	std::string		line;
	std::string		value;
	float			price;

	if (!openFileForRead(filePath, fileStream))
		throw std::runtime_error("could not open file.");

	getline(fileStream, line);
	if (line != FILE_HEADER)
		throw std::runtime_error("wrong file header.");
	while (getline(fileStream, line))
	{
		try
		{
			key = line.substr(0, line.find(" | "));
			value = line.substr(line.find(" | ") + 3);
			checkFormat(key, value, MAX_AMOUNT_VALUE);
			price = calculateDatePrice(key, value);
			std::cout << key << " => " << value << " = " << price << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "Error: bad input => '" << line << "'" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	fileStream.close();
}
