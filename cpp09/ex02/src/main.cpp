#include "PmergeMe/PmergeMe.hpp"
#include <iostream>

int	main()
{
	try
	{
		PmergeMe	pmerge;

		// int	nums[6] = { 10, 4, 5, 2, 1, 6 };
		int	nums[22] = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7 };
		pmerge.sortMergeInsertAlgorithm(nums, 22);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}
