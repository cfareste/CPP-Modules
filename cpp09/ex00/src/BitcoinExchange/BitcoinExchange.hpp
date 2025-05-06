#pragma once

#include <map>
#include <string>
#include <cstddef>
#include <fstream>

#define DATABASE_HEADER "date,exchange_rate"
#define FILE_HEADER "date | value"
#define MAX_AMOUNT_VALUE 1000
#define NO_KEY_FOUND "NO KEY FOUND"

class BitcoinExchange
{
private:
	std::map<std::string, float>	_database_values;

	BitcoinExchange();

	static bool	openFileForRead(const std::string &path, std::ifstream &fileStream);
	static bool	isInt(const std::string &str);
	static bool	isFloat(const std::string &str);
	static bool	areValidDateSeparators(const std::size_t &firstDash, const std::size_t &lastDash);
	static bool	areValidDateValues(const std::string &year, const std::string &month, const std::string &day);
	static void	checkDate(const std::string &date);
	static void	checkValue(const std::string &value, float maxValue);
	static void	checkFormat(const std::string &key, const std::string &value, float maxValue);
	void		loadDatabase(const std::string &databasePath);
	std::string	getClosestKey(const std::string &key);
	float		calculateDatePrice(const std::string &date, const std::string &amount);

public:
	BitcoinExchange(const std::string &databasePath);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	calculatePricesFromFile(const std::string &filePath);
};
