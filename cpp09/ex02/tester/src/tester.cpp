#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <streambuf>

#ifndef MAX_SIZE
# define MAX_SIZE 3000
#endif

#ifndef RANGE_TESTS_AMOUNT
# define RANGE_TESTS_AMOUNT 1000
#endif

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

	std::cout << "-----" << std::endl;
	std::cout << "Error:" << std::endl;
	PmergeMe().print("Initial vector", initialVector);
	PmergeMe().print("Sorted vector", vector);
	std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
	std::cout << "Comparisons (MAX = " << maxComparisons << "): " << comparisons << std::endl;
	std::cout << "-----" << std::endl;
	return true;
}

static void	executeRangeTests(int rangeSize)
{
	int		totalComparisons = 0;
	int		result = 0;
	double	totalTime = 0;

	for (int j = 0; j < RANGE_TESTS_AMOUNT; j++)
	{
		std::vector<int>	vector = getVector(rangeSize);
		std::vector<int>	initialVector = vector;

		double	time = 0;
		int		comparisons = executeSortingAlgorithm(vector, time);
		totalComparisons += comparisons;
		totalTime += time;
		result |= checkResults(vector, initialVector, comparisons);
	}

	std::cout.precision(5);
	std::cout.setf(std::ios::fixed);
	std::cout << "Tested " << rangeSize << " random numbers " << RANGE_TESTS_AMOUNT << " times: " << (!result ? "OK" : "KO")
		<< " | Avg. comparisons: " << totalComparisons / RANGE_TESTS_AMOUNT
		<< " / " << getMaxComparisons(rangeSize)
		<< " | Avg. time: " << totalTime / static_cast<double>(RANGE_TESTS_AMOUNT) * 1000 << " ms" << std::endl;
	std::cout.clear();
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
