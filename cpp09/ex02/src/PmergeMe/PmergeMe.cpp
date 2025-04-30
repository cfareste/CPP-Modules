#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
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

	this->vec = other.vec;
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

void	PmergeMe::initializeBoundsVectors(std::vector<int> &bounds, int lastPairSize)
{
	for (size_t i = lastPairSize - 1; i < this->vec.size(); i += lastPairSize)
	{
		bounds.push_back(this->vec.at(i));
	}
}

void	PmergeMe::initializePairVectors(std::vector<int> &pend, int elementsAmount, int lastPairSize, int legalElements)
{
	for (int i = elementsAmount; i < legalElements; i += lastPairSize)
	{
		pend.insert(pend.end(), this->vec.begin() + i, this->vec.begin() + i + lastPairSize);
		this->vec.erase(this->vec.begin() + i, this->vec.begin() + i + lastPairSize);
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

void	PmergeMe::insertMergeVector(int elementsAmount, int lastPairSize)
{
	if (this->vec.size() / lastPairSize <= 2)
		return ;

	std::vector<int>	pend;
	std::vector<int>	mainIndexes;
	std::vector<int>	pendIndexes;

	int	legalElements = (this->vec.size() / lastPairSize) * lastPairSize;
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
			this->vec.insert(this->vec.begin() + offset, pendIt - lastPairSize + 1, pendIt + 1);
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
	if (this->vec.size() < elementsAmount)
		return ;

	std::size_t	lastPairSize = elementsAmount >> 1;
	std::size_t	legalElements = (this->vec.size() / elementsAmount) * elementsAmount;
	for (std::size_t i = lastPairSize - 1; i < legalElements; i += elementsAmount)
	{
		if (isSmaller(this->vec.at(i), this->vec.at(i + lastPairSize)))
			continue ;

		for (int j = lastPairSize - 1; j >= 0; j--)
		{
			int	&firstNumber = this->vec.at(i - j);
			int	&secondNumber = this->vec.at(i - j + lastPairSize);
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
	this->vec = vector;
	this->sortVector(1);
	vector = this->vec;
	return PmergeMe::comparisons_;
}

void	PmergeMe::print(const std::string &title, std::vector<int> &vector)
{
	std::cout << title << " (" << vector.size() << "): ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
