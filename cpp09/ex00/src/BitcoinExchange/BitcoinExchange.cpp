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

void	BitcoinExchange::checkDate(const std::string &date)
{
	std::size_t	firstDash = date.find('-');
	std::size_t	lastDash = date.rfind('-');
	long		year = std::atol(date.substr(0, firstDash).c_str());
	long		month = std::atol(date.substr(firstDash + 1, lastDash - firstDash - 1).c_str());
	long		day = std::atol(date.substr(lastDash + 1).c_str());

	int	numOfSigns = 0;
	for (std::size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			numOfSigns++;
		else if (!std::isdigit(date[i]))
			throw std::invalid_argument("bad input => '" + date + "'");
	}
	if (year < 0 || year > std::numeric_limits<int>::max()
		|| month < 1 || month > 12
		|| day < 1 || day > 31
		|| (month == 2 && day > 29)
		|| numOfSigns != 2
		|| date.substr(firstDash + 1).length() != 5)
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
