#pragma once

#include <string>
#include <vector>

class PmergeMe
{
private:
	static int			comparisons_;
	std::vector<int>	vec;

	void	insertMerge(int elementsAmount, int lastPairSize);
	void	sort(int recursionLevel);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe	&operator=(const PmergeMe &other);
	~PmergeMe();

	static void	increaseComparisons();
	int			sortVectorFordJohnson(std::vector<int> &vector);

	void	print(const std::string &title, std::vector<int> &vector);

};
