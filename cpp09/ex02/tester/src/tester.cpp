#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <unistd.h>

#ifndef MAX_SIZE
# define MAX_SIZE 3000
#endif

#ifndef RANGE_TESTS_AMOUNT
# define RANGE_TESTS_AMOUNT 1000
#endif

#define GET_COLOR(color) (isatty(fileno(stdout)) ? color : "")

#define RESET		GET_COLOR("\033[0m")
#define RED			GET_COLOR("\033[0;31m")
#define RED_BOLD	GET_COLOR("\033[1;31m")
#define GREEN		GET_COLOR("\033[1;32m")
#define YELLOW		GET_COLOR("\033[0;33m")
#define PINK		GET_COLOR("\033[0;35m")
#define CYAN		GET_COLOR("\033[0;36m")
#define WHITE		GET_COLOR("\033[0;39m")
#define BOLDWHITE	GET_COLOR("\033[1;39m")

static void	printVector(const std::string &title, std::vector<int> &vector)
{
	std::cout << title;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static std::vector<int>	getVector(int size)
{
	std::vector<int>	vector;

	for (int i = 0; i < size; i++)
	{
		int	num = (rand() / static_cast<float>(RAND_MAX)) * 100000;
		vector.push_back(num);
	}

	return vector;
}

static bool	isSorted(std::vector<int> &vector)
{
	if (vector.empty())
		return true;

	for (std::vector<int>::iterator it = vector.begin() + 1; it != vector.end(); ++it)
	{
		if (*(it - 1) > *it)
			return false;
	}
	return true;
}

static int	getMaxComparisons(int n)
{
	int	sum = 0;
	for (int k = 1; k <= n; ++k) {
		double	value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

static int	executeSortingAlgorithm(std::vector<int> &vector, double &elapsedTime)
{
	PmergeMe			pmerge;
	std::streambuf		*coutCopy = std::cout.rdbuf();
	std::ostringstream	tempBuffer;

	std::cout.rdbuf(tempBuffer.rdbuf());
	clock_t	start = clock();
	int	comparisons = pmerge.sortVectorFordJohnson(vector);
	clock_t	finish = clock();
	elapsedTime = (finish - start) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout.rdbuf(coutCopy);

	return comparisons;
}

static bool	checkResults(std::vector<int> &vector, std::vector<int> &initialVector, int comparisons)
{
	int	maxComparisons = getMaxComparisons(initialVector.size());

	if (comparisons <= maxComparisons && isSorted(vector) && initialVector.size() == vector.size())
		return false;

	std::cout << RED << "-----" << std::endl;
	std::cout << "Error:" << std::endl;
	printVector("Initial vector", initialVector);
	printVector("Sorted vector", vector);
	std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
	std::cout << "Comparisons (MAX = " << maxComparisons << "): " << comparisons << std::endl;
	std::cout << "-----" << RESET << std::endl;
	return true;
}

static void printLogMessage(bool result, int rangeSize, double averageComparisons, double averageTime)
{
	int maxComparisons = getMaxComparisons(rangeSize);

	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);

	std::cout << CYAN << "Tested " << WHITE << rangeSize << CYAN << " random numbers "
			<< WHITE << RANGE_TESTS_AMOUNT << CYAN << " times: "
			<< (!result ? (std::string(GREEN) + "OK") : (std::string(RED_BOLD) + "KO")) << RESET
			<< " | " << YELLOW << "Avg. comparisons: " << RESET
			<< static_cast<int>(averageComparisons)
			<< " / " << maxComparisons << " max"
			<< " (" << YELLOW << averageComparisons / static_cast<double>(maxComparisons) * 100.0f << "%" << RESET << ")";

	std::cout.precision(5);
	std::cout << " | " << PINK << "Avg. time: " << RESET
			<< averageTime * 1000 << " ms" << std::endl;

	std::cout.clear();
}

static void	executeRangeTests(int rangeSize)
{
	int		result = 0;
	double	averageTime = 0;
	double	averageComparisons = 0;

	for (int j = 0; j < RANGE_TESTS_AMOUNT; j++)
	{
		std::vector<int>	vector = getVector(rangeSize);
		std::vector<int>	initialVector = vector;

		double	time = 0;
		int		comparisons = executeSortingAlgorithm(vector, time);
		averageTime += time;
		averageComparisons += comparisons;
		result |= checkResults(vector, initialVector, comparisons);
	}

	averageTime /= static_cast<double>(RANGE_TESTS_AMOUNT);
	averageComparisons /= static_cast<double>(RANGE_TESTS_AMOUNT);
	printLogMessage(result, rangeSize, averageComparisons, averageTime);
}

int	main()
{
	srand(time(NULL));

	try
	{
		for (int i = 1; i <= MAX_SIZE; i++)
			executeRangeTests(i);

		return EXIT_SUCCESS;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
	return EXIT_FAILURE;
}
