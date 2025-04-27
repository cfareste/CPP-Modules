#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

#define TOO_MUCH_COMPARISONS 2
#define VECTOR_NOT_SORTED 3
#define SIZES_MISMATCH 4

static bool	isSorted(std::vector<int>	&vector)
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

static std::vector<int>	getVector(int argc, char **argv)
{
	std::vector<int>	vector;

	for (int i = 1; i < argc; i++)
	{
		vector.push_back(std::atof(argv[i]));
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

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	pmerge;

		std::vector<int>	vector = getVector(argc, argv);
		int	previousSize = vector.size();
		int	maxComparisons = getMaxComparisons(vector.size());
		int	comparisons = pmerge.sortVectorFordJohnson(vector);

		std::cout << "Comparisons: " << comparisons << std::endl;

		if (comparisons > maxComparisons)
			return TOO_MUCH_COMPARISONS;
		if (!isSorted(vector))
			return VECTOR_NOT_SORTED;
		if (previousSize != static_cast<int>(vector.size()))
			return SIZES_MISMATCH;
		return EXIT_SUCCESS;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_FAILURE;
}
