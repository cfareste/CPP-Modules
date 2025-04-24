#pragma once

#include <string>
#include <vector>

class PmergeMe
{
private:
	std::vector<int>	vec;

	void	insertMerge(int recursionLevel, int elementsAmount, int lastPairSize);
	void	sort(int recursionLevel);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe	&operator=(const PmergeMe &other);
	~PmergeMe();

	void	sortMergeInsertAlgorithm(int *numbers, int size);

	void	print();

};
