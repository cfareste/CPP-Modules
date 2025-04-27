#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#define TOO_MUCH_COMPARISONS 2
#define VECTOR_NOT_SORTED 3
#define SIZES_MISMATCH 5

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

int	main()
{
	try
	{
		PmergeMe			pmerge;
		std::vector<int>	vector;
		std::vector<int>	copyVector;

		int	coutCopy = dup(STDOUT_FILENO);
		int	devNull = open("/dev/null", O_WRONLY);

		dup2(devNull, STDOUT_FILENO);

		for (int i = 2; i <= 3000; i++)
		{
			srand(time(NULL));
			std::cerr << "Testing with " << i << " nums..." << std::endl;
			for (int j = 0; j < 1000; j++)
			{
				vector = getVector(i);
				copyVector = vector;
				int	previousSize = vector.size();
				int	maxComparisons = getMaxComparisons(vector.size());
				int	comparisons = pmerge.sortVectorFordJohnson(vector);

				if (comparisons > maxComparisons
					|| !isSorted(vector)
					|| previousSize != static_cast<int>(vector.size()))
				{
					dup2(coutCopy, STDOUT_FILENO);
					std::cout << "Error" << std::endl;
					pmerge.print("Vector", copyVector);
					std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
					std::cout << "Comparisons (MAX = " << maxComparisons << "): " << comparisons << std::endl;
					dup2(devNull, STDOUT_FILENO);
				}
			}
		}
		close(coutCopy);
		close(devNull);
		return EXIT_SUCCESS;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_FAILURE;
}
