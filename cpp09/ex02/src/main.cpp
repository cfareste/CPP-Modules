#include "PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <cmath>

static bool	isSorted(std::vector<int>	&vector)
{
	for (std::vector<int>::iterator it = vector.begin() + 1; it != vector.end(); ++it)
	{
		if (*(it - 1) > *it)
			return false;
	}
	return true;
}

static std::vector<int>	getVector()
{
	// int	nums[1] = { 1 };
	// int	nums[2] = { 3, 1 };
	// int	nums[3] = { 3, 2, 1 };
	// int	nums[4] = { 4, 1, 3, 2 };
	// int	nums[6] = { 0, 4, 5, 2, 1, 6 };
	int	nums[18] = { 15, 6, 7, 14, 10, 17, 13, 11, 18, 1, 9, 16, 8, 12, 3, 4, 5, 2 };
	// int	nums[21] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7 };
	// int	nums[22] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7 };
	// int	nums[23] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 22, 19, 12, 5, 4, 20, 13, 7 };
	// int	nums[24] = { 11, 2, 17, 0, 16, 8, 23, 6, 15, 10, 3, 21, 1, 18, 9, 14, 22, 19, 12, 5, 4, 20, 13, 7 };

	return std::vector<int>(nums, nums + (sizeof(nums) / sizeof(int)));
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
		PmergeMe	pmerge;

		std::vector<int>	vector = getVector();
		std::cout << "Max comparisons with this vector: " << getMaxComparisons(vector.size()) << std::endl;
		std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
		int	comparisons = pmerge.sortVectorFordJohnson(vector);
		std::cout << "Comparisons: " << comparisons << std::endl;
		std::cout << "Is sorted: " << (isSorted(vector) ? "yes" : "no") << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
