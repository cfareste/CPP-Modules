#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <iostream>

static void	printVector(const std::string &title, std::vector<int> &vector)
{
	std::cout << title;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static std::vector<int>	getVector(int argc, char **argv)
{
	std::vector<int>	vector;

	for (int i = 1; i < argc; i++)
	{
		vector.push_back(std::atoi(argv[i]));
	}

	return vector;
}

static std::deque<int>	getDeque(int argc, char **argv)
{
	std::deque<int>	deque;

	for (int i = 1; i < argc; i++)
	{
		deque.push_back(std::atoi(argv[i]));
	}

	return deque;
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
		PmergeMe			pmerge;
		std::deque<int>		deque = getDeque(argc, argv);
		std::vector<int>	vector = getVector(argc, argv);

		printVector("Before: ", vector);

		clock_t	init = clock();
		int	comparisons = pmerge.sortVectorFordJohnson(vector);
		clock_t	end = clock();
		double	vectorTime = ((end - init) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;

		init = clock();
		pmerge.sortDequeFordJohnson(deque);
		end = clock();
		double	dequeTime = ((end - init) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;

		printVector("After:  ", vector);

		std::cout << "Comparisons: " << comparisons << " (MAX = " << getMaxComparisons(vector.size()) << ")" << std::endl;
		std::cout << "Time to process a range of " << std::setw(4) << vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
		std::cout << "Time to process a range of " << std::setw(4) << vector.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
