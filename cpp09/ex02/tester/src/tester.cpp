#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <streambuf>

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

static int	getMaxComparisons(int n)
{
	int	sum = 0;
	for (int k = 1; k <= n; ++k) {
		double	value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

static int	executeSortingAlgorithm(std::vector<int> &vector)
{
	PmergeMe			pmerge;
	std::streambuf		*coutCopy = std::cout.rdbuf();
	std::ostringstream	tempBuffer;

	std::cout.rdbuf(tempBuffer.rdbuf());
	int	comparisons = pmerge.sortVectorFordJohnson(vector);
	std::cout.rdbuf(coutCopy);

	return comparisons;
}

static void	checkResults(std::vector<int> &vector, std::vector<int> &initialVector, int comparisons)
{
	int	maxComparisons = getMaxComparisons(initialVector.size());

	if (comparisons <= maxComparisons && isSorted(vector) && initialVector.size() == vector.size())
		return ;

	std::cout << "-----" << std::endl;
	std::cout << "Error:" << std::endl;
	PmergeMe().print("Initial vector", initialVector);
	PmergeMe().print("Sorted vector", vector);
	std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
	std::cout << "Comparisons (MAX = " << maxComparisons << "): " << comparisons << std::endl;
	std::cout << "-----" << std::endl;
}

int	main()
{
	srand(time(NULL));

	try
	{
		for (int i = 2; i <= 3000; i++)
		{
			std::cout << "Testing with " << i << " numbers..." << std::endl;

			for (int j = 0; j < 1000; j++)
			{
				std::vector<int>	vector = getVector(i);
				std::vector<int>	initialVector = vector;

				int	comparisons = executeSortingAlgorithm(vector);
				checkResults(vector, initialVector, comparisons);
			}
		}
		return EXIT_SUCCESS;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
	return EXIT_FAILURE;
}
