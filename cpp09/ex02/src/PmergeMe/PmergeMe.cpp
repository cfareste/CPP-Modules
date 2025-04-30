#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

int	PmergeMe::comparisons_ = 0;

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;

	this->vec_ = other.vec_;
	this->deq_ = other.deq_;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static bool	isSmaller(int lval, int rval)
{
	PmergeMe::increaseComparisons();
	return lval < rval;
}

static int	getJacobsthal(int index)
{
	int	n1 = 1;
	int	n2 = 0;
	int	res = 0;

	for (int i = 0; i < index; i++)
	{
		res = n1 + (2 * n2);
		n2 = n1;
		n1 = res;
	}

	return res;
}

int	PmergeMe::initializePendIndexIterator(int jacobsthal, int totalInserted, int pendIndexesSize)
{
	int	pendIndexIte = jacobsthal - totalInserted + 1;
	if (pendIndexIte > pendIndexesSize)
	{
		pendIndexIte = pendIndexesSize;
	}
	pendIndexIte--;

	return pendIndexIte;
}

void	PmergeMe::initializeBoundsDeques(std::deque<int> &bounds, int lastPairSize)
{
	for (size_t i = lastPairSize - 1; i < this->deq_.size(); i += lastPairSize)
	{
		bounds.push_back(this->deq_.at(i));
	}
}

void	PmergeMe::initializePairDeques(std::deque<int> &pend, int elementsAmount, int lastPairSize, int legalElements)
{
	for (int i = elementsAmount; i < legalElements; i += lastPairSize)
	{
		pend.insert(pend.end(), this->deq_.begin() + i, this->deq_.begin() + i + lastPairSize);
		this->deq_.erase(this->deq_.begin() + i, this->deq_.begin() + i + lastPairSize);
		legalElements -= lastPairSize;
	}
}

void	PmergeMe::initializeIndexDeques(std::deque<int> &mainIdx, std::deque<int> &pendIdx, int mainSize, int pendSize)
{
	mainIdx.push_back(-1);
	for (int i = 1; i < mainSize; i++)
	{
		mainIdx.push_back(i);
	}
	for (int i = 0; i < pendSize; i++)
	{
		pendIdx.push_back((i + 2) * -1);
	}
}

void	PmergeMe::insertMergeDeque(int elementsAmount, int lastPairSize)
{
	if (this->deq_.size() / lastPairSize <= 2)
		return ;

	std::deque<int>	pend;
	std::deque<int>	mainIndexes;
	std::deque<int>	pendIndexes;

	int	legalElements = (this->deq_.size() / lastPairSize) * lastPairSize;
	this->initializePairDeques(pend, elementsAmount, lastPairSize, legalElements);

	int	mainSize = legalElements / lastPairSize;
	int	pendSize = static_cast<int>(pend.size()) / lastPairSize;
	this->initializeIndexDeques(mainIndexes, pendIndexes, mainSize, pendSize);

	std::deque<int>	bounds;
	this->initializeBoundsDeques(bounds, lastPairSize);

	int	insertedElements = 0, offset = 0, pendIndexIte = 0, totalInserted = 2, jacobsthalIndex = 2;
	std::deque<int>::iterator	boundMain, insertionIt, pendIt;
	while (!pend.empty())
	{
		pendIndexIte = initializePendIndexIterator(getJacobsthal(jacobsthalIndex), totalInserted, pendIndexes.size());
		pendIt = pend.begin() + (pendIndexIte * lastPairSize) + lastPairSize - 1;

		insertedElements = 0;
		for (; pendIndexIte >= 0; --pendIndexIte)
		{
			boundMain = std::find(mainIndexes.begin(), mainIndexes.end(), pendIndexes.at(pendIndexIte) * -1);
			insertionIt = std::upper_bound(bounds.begin(), bounds.begin() + (boundMain - mainIndexes.begin()), *pendIt, isSmaller);
			offset = (insertionIt - bounds.begin()) * lastPairSize;
			bounds.insert(insertionIt, *pendIt);
			this->deq_.insert(this->deq_.begin() + offset, pendIt - lastPairSize + 1, pendIt + 1);
			mainIndexes.insert(mainIndexes.begin() + (offset / lastPairSize), pendIndexes.at(pendIndexIte));
			pendIt -= lastPairSize;
			insertedElements++;
		}
		totalInserted += insertedElements;
		pend.erase(pend.begin(), pend.begin() + (lastPairSize * insertedElements));
		pendIndexes.erase(pendIndexes.begin(), pendIndexes.begin() + insertedElements);
		jacobsthalIndex++;
	}
}

void	PmergeMe::sortDeque(int recursionLevel)
{
	std::size_t	elementsAmount = 2 << (recursionLevel - 1);
	if (this->deq_.size() < elementsAmount)
		return ;

	std::size_t	lastPairSize = elementsAmount >> 1;
	std::size_t	legalElements = (this->deq_.size() / elementsAmount) * elementsAmount;
	for (std::size_t i = lastPairSize - 1; i < legalElements; i += elementsAmount)
	{
		if (isSmaller(this->deq_.at(i), this->deq_.at(i + lastPairSize)))
			continue ;

		for (int j = lastPairSize - 1; j >= 0; j--)
		{
			int	&firstNumber = this->deq_.at(i - j);
			int	&secondNumber = this->deq_.at(i - j + lastPairSize);
			std::swap(firstNumber, secondNumber);
		}
	}

	this->sortDeque(recursionLevel + 1);
	this->insertMergeDeque(elementsAmount, lastPairSize);
}

void	PmergeMe::initializeBoundsVectors(std::vector<int> &bounds, int lastPairSize)
{
	for (size_t i = lastPairSize - 1; i < this->vec_.size(); i += lastPairSize)
	{
		bounds.push_back(this->vec_.at(i));
	}
}

void	PmergeMe::initializePairVectors(std::vector<int> &pend, int elementsAmount, int lastPairSize, int legalElements)
{
	for (int i = elementsAmount; i < legalElements; i += lastPairSize)
	{
		pend.insert(pend.end(), this->vec_.begin() + i, this->vec_.begin() + i + lastPairSize);
		this->vec_.erase(this->vec_.begin() + i, this->vec_.begin() + i + lastPairSize);
		legalElements -= lastPairSize;
	}
}

void	PmergeMe::initializeIndexVectors(std::vector<int> &mainIdx, std::vector<int> &pendIdx, int mainSize, int pendSize)
{
	mainIdx.push_back(-1);
	for (int i = 1; i < mainSize; i++)
	{
		mainIdx.push_back(i);
	}
	for (int i = 0; i < pendSize; i++)
	{
		pendIdx.push_back((i + 2) * -1);
	}
}

void	PmergeMe::insertMergeVector(int elementsAmount, int lastPairSize)
{
	if (this->vec_.size() / lastPairSize <= 2)
		return ;

	std::vector<int>	pend;
	std::vector<int>	mainIndexes;
	std::vector<int>	pendIndexes;

	int	legalElements = (this->vec_.size() / lastPairSize) * lastPairSize;
	this->initializePairVectors(pend, elementsAmount, lastPairSize, legalElements);

	int	mainSize = legalElements / lastPairSize;
	int	pendSize = static_cast<int>(pend.size()) / lastPairSize;
	this->initializeIndexVectors(mainIndexes, pendIndexes, mainSize, pendSize);

	std::vector<int>	bounds;
	this->initializeBoundsVectors(bounds, lastPairSize);

	int	insertedElements = 0, offset = 0, pendIndexIte = 0, totalInserted = 2, jacobsthalIndex = 2;
	std::vector<int>::iterator	boundMain, insertionIt, pendIt;
	while (!pend.empty())
	{
		pendIndexIte = initializePendIndexIterator(getJacobsthal(jacobsthalIndex), totalInserted, pendIndexes.size());
		pendIt = pend.begin() + (pendIndexIte * lastPairSize) + lastPairSize - 1;

		insertedElements = 0;
		for (; pendIndexIte >= 0; --pendIndexIte)
		{
			boundMain = std::find(mainIndexes.begin(), mainIndexes.end(), pendIndexes.at(pendIndexIte) * -1);
			insertionIt = std::upper_bound(bounds.begin(), bounds.begin() + (boundMain - mainIndexes.begin()), *pendIt, isSmaller);
			offset = (insertionIt - bounds.begin()) * lastPairSize;
			bounds.insert(insertionIt, *pendIt);
			this->vec_.insert(this->vec_.begin() + offset, pendIt - lastPairSize + 1, pendIt + 1);
			mainIndexes.insert(mainIndexes.begin() + (offset / lastPairSize), pendIndexes.at(pendIndexIte));
			pendIt -= lastPairSize;
			insertedElements++;
		}
		totalInserted += insertedElements;
		pend.erase(pend.begin(), pend.begin() + (lastPairSize * insertedElements));
		pendIndexes.erase(pendIndexes.begin(), pendIndexes.begin() + insertedElements);
		jacobsthalIndex++;
	}
}

void	PmergeMe::sortVector(int recursionLevel)
{
	std::size_t	elementsAmount = 2 << (recursionLevel - 1);
	if (this->vec_.size() < elementsAmount)
		return ;

	std::size_t	lastPairSize = elementsAmount >> 1;
	std::size_t	legalElements = (this->vec_.size() / elementsAmount) * elementsAmount;
	for (std::size_t i = lastPairSize - 1; i < legalElements; i += elementsAmount)
	{
		if (isSmaller(this->vec_.at(i), this->vec_.at(i + lastPairSize)))
			continue ;

		for (int j = lastPairSize - 1; j >= 0; j--)
		{
			int	&firstNumber = this->vec_.at(i - j);
			int	&secondNumber = this->vec_.at(i - j + lastPairSize);
			std::swap(firstNumber, secondNumber);
		}
	}

	this->sortVector(recursionLevel + 1);
	this->insertMergeVector(elementsAmount, lastPairSize);
}

void	PmergeMe::increaseComparisons()
{
	PmergeMe::comparisons_++;
}

int	PmergeMe::sortVectorFordJohnson(std::vector<int> &vector)
{
	PmergeMe::comparisons_ = 0;
	this->vec_ = vector;
	this->sortVector(1);
	vector = this->vec_;
	return PmergeMe::comparisons_;
}

int	PmergeMe::sortDequeFordJohnson(std::deque<int> &deque)
{
	PmergeMe::comparisons_ = 0;
	this->deq_ = deque;
	this->sortDeque(1);
	deque = this->deq_;
	return PmergeMe::comparisons_;
}
