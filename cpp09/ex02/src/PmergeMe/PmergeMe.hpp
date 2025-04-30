#pragma once

#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
private:
	static int			comparisons_;
	std::deque<int>		deq_;
	std::vector<int>	vec_;

	int		initializePendIndexIterator(int jacobsthal, int totalInserted, int pendIndexesSize);

	void	initializeBoundsVectors(std::vector<int> &bounds, int lastPairSize);
	void	initializePairVectors(std::vector<int> &pend, int elementsAmount, int lastPairSize, int legalElements);
	void	initializeIndexVectors(std::vector<int> &mainIdx, std::vector<int> &pendIdx, int mainSize, int pendSize);
	void	insertMergeVector(int elementsAmount, int lastPairSize);
	void	sortVector(int recursionLevel);

	void	initializeBoundsDeques(std::deque<int> &bounds, int lastPairSize);
	void	initializePairDeques(std::deque<int> &pend, int elementsAmount, int lastPairSize, int legalElements);
	void	initializeIndexDeques(std::deque<int> &mainIdx, std::deque<int> &pendIdx, int mainSize, int pendSize);
	void	insertMergeDeque(int elementsAmount, int lastPairSize);
	void	sortDeque(int recursionLevel);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe	&operator=(const PmergeMe &other);
	~PmergeMe();

	static void	increaseComparisons();
	int			sortVectorFordJohnson(std::vector<int> &vector);
	int			sortDequeFordJohnson(std::deque<int> &deque);
};
