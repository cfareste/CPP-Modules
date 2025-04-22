#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>

#define DATABASE_PATH "data.csv"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		BitcoinExchange	btc = BitcoinExchange(DATABASE_PATH);

		btc.calculatePricesFromFile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
