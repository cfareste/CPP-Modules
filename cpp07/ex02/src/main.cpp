#include "Array/Array.hpp"
#include <iostream>
#include <string>

int	main()
{
	const Array<int>	numbers(10);

	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		numbers[i] = static_cast<int>(i) * 10;
		std::cout << numbers[i] << std::endl;
	}
	std::cout << std::endl;

	Array<std::string>	words(5);

	words[0] = "Animal";
	words[1] = "Zoo";
	words[2] = "Zebra";
	words[3] = "Snake";
	words[4] = "Lion";

	Array<std::string>	words2 = words;

	words2[0] = "Car";
	words2[1] = "Speed";
	words2[2] = "Wheel";
	words2[3] = "Driver";
	words2[4] = "Chasis";

	for (int i = -1; i < static_cast<int>(words.size() + 3); i++)
	{
		try
		{
			std::string cache1 = words[i];
			std::string cache2 = words2[i];
			std::cout << "word[" << i << "] = " << cache1 << " - > ";
			std::cout << "word2[" << i << "] = " << cache2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "word[" << i << "] = " << e.what() << " - > ";
			std::cout << "word2[" << i << "] = " << e.what() << std::endl;
		}
	}

	Array<std::string>	nullTest;
	try
	{
		std::cout << "word = " << nullTest[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "word = " << e.what() << std::endl;
	}

	Array<const int>	constArray(10);

	for (std::size_t i = 0; i < constArray.size() + 1; i++)
	{
		try
		{
			std::cout << constArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "constArray[" << i << "]: " << e.what() << std::endl;
		}
	}

	Array<int>	array(5);
	Array<int>	array2(10);

	std::cout << "array = " << array.size() << std::endl;
	std::cout << "array2 = " << array2.size() << std::endl;
	for (std::size_t i = 0; i < array2.size(); i++)
	{
		try
		{
			array[i] = static_cast<int>(i);
			array2[i] = static_cast<int>(i) + 10;
		}
		catch(const std::exception& e) {}
	}

	array2 = array;
	std::cout << "array = " << array.size() << std::endl;
	std::cout << "array2 = " << array2.size() << std::endl;
	for (std::size_t i = 0; i < array.size(); i++)
	{
		try
		{
			std::cout << array[i] << std::endl;
			std::cout << array2[i] << std::endl;
		}
		catch(const std::exception& e) {}
	}
}
