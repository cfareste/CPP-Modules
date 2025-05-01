#include "PmergeMe/PmergeMe.hpp"
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <sstream>
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

static int	getMaxComparisons(int n)
{
	int	sum = 0;
	for (int k = 1; k <= n; ++k) {
		double	value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

static bool	isInt(char *str)
{
	int					num;
	std::istringstream	stream(str);

	stream >> std::noskipws >> num;
	return stream.eof() && !stream.fail();
}

static bool	isNegative(char *argv)
{
	return argv[0] == '-';
}

static bool	areValidArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isInt(argv[i]) || isNegative(argv[i]))
			return false;
	}
	return true;
}

static bool	hasDuplicates(std::vector<int> vector)
{
	std::sort(vector.begin(), vector.end());
	return std::adjacent_find(vector.begin(), vector.end()) != vector.end();
}

int	main(int argc, char **argv)
{
	if (argc < 2 || !areValidArgs(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		PmergeMe			pmerge;
		std::vector<int>	vector = getVector(argc, argv);
		std::deque<int>		deque(vector.begin(), vector.end());

		if (hasDuplicates(vector))
			throw std::invalid_argument("Sequence contains duplicates");

		printVector("Before: ", vector);

		clock_t	init = clock();
		int	comparisons = pmerge.sortVectorFordJohnson(vector);
		clock_t	end = clock();
		double	vectorTime = ((end - init) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;

		init = clock();
		pmerge.sortDequeFordJohnson(deque);
		end = clock();
		double	dequeTime = ((end - init) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;

		printVector("After:  ", vector);

		std::cout << "Comparisons: " << comparisons << " (MAX = " << getMaxComparisons(vector.size()) << ")" << std::endl;
		std::cout << "Time to process a range of " << std::setw(4) << vector.size() << " elements with std::vector : " << vectorTime << " ms" << std::endl;
		std::cout << "Time to process a range of " << std::setw(4) << vector.size() << " elements with std::deque : " << dequeTime << " ms" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
