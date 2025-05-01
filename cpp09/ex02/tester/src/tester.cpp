#include "PmergeMe/PmergeMe.hpp"
#include "TestResult/TestResult.hpp"
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

template<typename T>
static void	printContainer(const std::string &title, T &container)
{
	std::cout << title;
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
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

template <typename T>
static bool	isSorted(T &container)
{
	if (container.empty())
		return true;

	for (typename T::iterator it = container.begin() + 1; it != container.end(); ++it)
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

static TestResult	executeSortingAlgorithm(std::vector<int> &vector, std::deque<int> &deque)
{
	PmergeMe			pmerge;
	TestResult			result;
	std::streambuf		*coutCopy = std::cout.rdbuf();
	std::ostringstream	tempBuffer;

	std::cout.rdbuf(tempBuffer.rdbuf());
	clock_t	start = clock();
	result.setVectorComparisons(pmerge.sortVectorFordJohnson(vector));
	clock_t	finish = clock();
	result.setVectorElapsedTime((finish - start) / static_cast<double>(CLOCKS_PER_SEC));
	start = clock();
	result.setDequeComparisons(pmerge.sortDequeFordJohnson(deque));
	finish = clock();
	result.setDequeElapsedTime((finish - start) / static_cast<double>(CLOCKS_PER_SEC));
	std::cout.rdbuf(coutCopy);

	return result;
}

static bool	checkResults(std::vector<int> &vector, std::deque<int> &deque, std::vector<int> &initialVector, TestResult &result)
{
	int	maxComparisons = getMaxComparisons(initialVector.size());

	if (result.getVectorComparisons() <= maxComparisons
		&& result.getDequeComparisons() == result.getVectorComparisons()
		&& isSorted(vector) && isSorted(deque)
		&& initialVector.size() == vector.size()
		&& initialVector.size() == deque.size())
		return false;

	std::cout << RED << "-----" << std::endl;
	std::cout << "Error:" << std::endl;
	printContainer("Initial sequence: ", initialVector);
	std::cout << "Sequences sizes: Initial = " << initialVector.size()
		<< " | Sorted vector / deque = " << vector.size() << " / " << deque.size() << std::endl;
	std::cout << "Is vector sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
	std::cout << "Is deque sorted: " << (isSorted(deque) ? "yes" : "no") << std::endl;
	std::cout << "Vector comparisons (MAX = " << maxComparisons << "): " << result.getVectorComparisons() << std::endl;
	std::cout << "Deque comparisons (MAX = " << maxComparisons << "): " << result.getDequeComparisons() << std::endl;
	std::cout << "-----" << RESET << std::endl;
	return true;
}

static void printLogMessage(TestResult &rangeTestsResult, int rangeSize)
{
	int maxComparisons = getMaxComparisons(rangeSize);

	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);

	std::cout << CYAN << "Tested " << WHITE << rangeSize << CYAN << " random numbers "
			<< WHITE << RANGE_TESTS_AMOUNT << CYAN << " times: "
			<< (!rangeTestsResult.hasFailed() ? (std::string(GREEN) + "OK") : (std::string(RED_BOLD) + "KO")) << RESET
			<< " | " << YELLOW << "Avg. comparisons: " << RESET
			<< static_cast<int>(rangeTestsResult.getVectorComparisons())
			<< " / " << maxComparisons << " max"
			<< " (" << YELLOW << rangeTestsResult.getVectorComparisons() / static_cast<double>(maxComparisons) * 100.0f << "%" << RESET << ")";

	std::cout.precision(5);
	std::cout << " | " << PINK << "Avg. vector time: " << RESET
			<< rangeTestsResult.getVectorElapsedTime() * 1000 << " ms"
			<< " | " << PINK << "Avg. deque time: " << RESET
			<< rangeTestsResult.getDequeElapsedTime() * 1000 << " ms" << std::endl;

	std::cout.clear();
}

static void	executeRangeTests(int rangeSize)
{
	TestResult	executionResult;
	TestResult	rangeTestsResult;

	for (int j = 0; j < RANGE_TESTS_AMOUNT; j++)
	{
		std::vector<int>	vector = getVector(rangeSize);
		std::vector<int>	initialVector = vector;
		std::deque<int>		deque(vector.begin(), vector.end());

		executionResult = executeSortingAlgorithm(vector, deque);
		rangeTestsResult += executionResult;
		int	testStatus = checkResults(vector, deque, initialVector, executionResult);
		rangeTestsResult.addTestFailedStatus(testStatus);
	}

	rangeTestsResult /= static_cast<double>(RANGE_TESTS_AMOUNT);
	printLogMessage(rangeTestsResult, rangeSize);
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
