#pragma once

#include <string>
#include <vector>

class PmergeMe
{
private:
	static int			comparisons_;
	std::vector<int>	vec;

	void	initializePairVectors(std::vector<int> &pend, int elementsAmount, int lastPairSize, int legalElements);
	void	initializeIndexVectors(std::vector<int> &mainIdx, std::vector<int> &pendIdx, int mainSize, int pendSize);
	void	insertMergeVector(int elementsAmount, int lastPairSize);
	void	sortVector(int recursionLevel);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe	&operator=(const PmergeMe &other);
	~PmergeMe();

	static void	increaseComparisons();
	int			sortVectorFordJohnson(std::vector<int> &vector);

	void	print(const std::string &title, std::vector<int> &vector);

};
