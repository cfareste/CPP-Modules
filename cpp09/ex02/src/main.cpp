#include "PmergeMe/PmergeMe.hpp"
#include <iostream>

int	main()
{
	try
	{
		PmergeMe	pmerge;

		// int	nums[1] = { 1 };
		// int	nums[2] = { 3, 1 };
		// int	nums[3] = { 3, 2, 1 };
		// int	nums[4] = { 4, 1, 3, 2 };
		// int	nums[6] = { 0, 4, 5, 2, 1, 6 };
		// int	nums[22] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7 };
		int	nums[23] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 22, 19, 12, 5, 4, 20, 13, 7 };
		// int	nums[24] = { 11, 2, 17, 0, 16, 8, 23, 6, 15, 10, 3, 21, 1, 18, 9, 14, 22, 19, 12, 5, 4, 20, 13, 7 };
		pmerge.sortMergeInsertAlgorithm(nums, sizeof(nums) / sizeof(int));
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
