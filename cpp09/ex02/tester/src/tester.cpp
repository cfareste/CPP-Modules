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

typedef struct s_Result
{
	bool	failed;
	int		vectorComparisons;
	int		dequeComparisons;
	double	vectorElapsedTime;
	double	dequeElapsedTime;
}	t_Result;

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

static t_Result	executeSortingAlgorithm(std::vector<int> &vector, std::deque<int> &deque)
{
	PmergeMe			pmerge;
	t_Result			result;
	std::streambuf		*coutCopy = std::cout.rdbuf();
	std::ostringstream	tempBuffer;

	std::cout.rdbuf(tempBuffer.rdbuf());
	clock_t	start = clock();
	result.vectorComparisons = pmerge.sortVectorFordJohnson(vector);
	clock_t	finish = clock();
	result.vectorElapsedTime = (finish - start) / static_cast<double>(CLOCKS_PER_SEC);
	start = clock();
	result.dequeComparisons = pmerge.sortDequeFordJohnson(deque);
	finish = clock();
	result.dequeElapsedTime = (finish - start) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout.rdbuf(coutCopy);

	return result;
}

static bool	checkResults(std::vector<int> &vector, std::deque<int> &deque, std::vector<int> &initialVector, t_Result &executionResult)
{
	int	maxComparisons = getMaxComparisons(initialVector.size());

	if (executionResult.vectorComparisons <= maxComparisons
		&& executionResult.dequeComparisons == executionResult.vectorComparisons
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
	std::cout << "Vector comparisons (MAX = " << maxComparisons << "): " << executionResult.vectorComparisons << std::endl;
	std::cout << "Deque comparisons (MAX = " << maxComparisons << "): " << executionResult.dequeComparisons << std::endl;
	std::cout << "-----" << RESET << std::endl;
	return true;
}

static void printLogMessage(t_Result &rangeTestsResult, int rangeSize)
{
	int maxComparisons = getMaxComparisons(rangeSize);

	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);

	std::cout << CYAN << "Tested " << WHITE << rangeSize << CYAN << " random numbers "
			<< WHITE << RANGE_TESTS_AMOUNT << CYAN << " times: "
			<< (!rangeTestsResult.failed ? (std::string(GREEN) + "OK") : (std::string(RED_BOLD) + "KO")) << RESET
			<< " | " << YELLOW << "Avg. comparisons: " << RESET
			<< static_cast<int>(rangeTestsResult.vectorComparisons)
			<< " / " << maxComparisons << " max"
			<< " (" << YELLOW << rangeTestsResult.vectorComparisons / static_cast<double>(maxComparisons) * 100.0f << "%" << RESET << ")";

	std::cout.precision(5);
	std::cout << " | " << PINK << "Avg. vector time: " << RESET
			<< rangeTestsResult.vectorElapsedTime * 1000 << " ms"
			<< " | " << PINK << "Avg. deque time: " << RESET
			<< rangeTestsResult.dequeElapsedTime * 1000 << " ms" << std::endl;

	std::cout.clear();
}

static void	executeRangeTests(int rangeSize)
{
	t_Result	executionResult;
	t_Result	rangeTestsResult;

	rangeTestsResult.failed = false;
	rangeTestsResult.dequeElapsedTime = 0;
	rangeTestsResult.vectorComparisons = 0;
	rangeTestsResult.vectorElapsedTime = 0;
	for (int j = 0; j < RANGE_TESTS_AMOUNT; j++)
	{
		std::vector<int>	vector = getVector(rangeSize);
		std::vector<int>	initialVector = vector;
		std::deque<int>		deque(vector.begin(), vector.end());

		executionResult = executeSortingAlgorithm(vector, deque);
		rangeTestsResult.dequeElapsedTime += executionResult.dequeElapsedTime;
		rangeTestsResult.vectorElapsedTime += executionResult.vectorElapsedTime;
		rangeTestsResult.vectorComparisons += executionResult.vectorComparisons;
		rangeTestsResult.failed |= checkResults(vector, deque, initialVector, executionResult);
	}

	rangeTestsResult.dequeElapsedTime /= static_cast<double>(RANGE_TESTS_AMOUNT);
	rangeTestsResult.vectorElapsedTime /= static_cast<double>(RANGE_TESTS_AMOUNT);
	rangeTestsResult.vectorComparisons /= static_cast<double>(RANGE_TESTS_AMOUNT);
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
