#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
#include <algorithm>

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

void	PmergeMe::insertMerge(int recursionLevel, int elementsAmount, int lastPairSize)
{
	if (this->vec.size() / lastPairSize <= 2)
		return ;

	std::vector<int>	pend;
	std::vector<int>	mainIndexes;
	std::vector<int>	pendIndexes;

	int	legalElements = (this->vec.size() / lastPairSize) * lastPairSize;
	int	nonParticipatingAmount = this->vec.size() - legalElements;
	(void) nonParticipatingAmount;
	std::cout << "Elements: " << elementsAmount << " | Size: " << this->vec.size() << std::endl;
	std::cout << "Legals: " << legalElements << " | Rec: " << recursionLevel << std::endl;

	for (int i = elementsAmount; i < legalElements; i += lastPairSize)
	{
		std::cout << "Value at " << i << ": " << this->vec.at(i) << std::endl;
		for (int j = 0; i < legalElements && j < lastPairSize; j++)
		{
			std::cout << "Iteration: i: " << i << " | j: " << j << std::endl;
			pend.push_back(this->vec.at(i));
			this->vec.erase(this->vec.begin() + i);
			legalElements--;
		}
		this->print("Main", this->vec);
		this->print("Pend", pend);
		// std::cout << "New value at " << i << ": " << std::flush << this->vec.at(i) << std::endl;
	}

	this->print("Main vec", this->vec);
	this->print("Pend vec", pend);

	mainIndexes.push_back(-1);
	mainIndexes.push_back(1);
	for (int i = 2; i < legalElements / lastPairSize; i++)
	{
		mainIndexes.push_back(i);
	}
	for (int i = 0; i < static_cast<int>(pend.size()) / lastPairSize; i++)
	{
		pendIndexes.push_back((i + 2) * -1);
	}

	this->print("Pend indexes", pendIndexes);
	this->print("Main indexes", mainIndexes);

	int	jacobsthalIndex = 2;
	// int	previousJacobsthal = 1;

	std::vector<int>	pairBounds;
	for (size_t i = lastPairSize - 1; i < this->vec.size(); i += lastPairSize)
	{
		pairBounds.push_back(this->vec.at(i));
	}
	this->print("bounds:", pairBounds);
	std::vector<int>::iterator	boundMain;
	std::vector<int>::iterator	insertionIt;
	std::vector<int>::iterator	pendIt;
	std::vector<int>::reverse_iterator	pendIndexIt;
	int	inserted = 2;
	while (!pend.empty())
	{
		int	jacobsthal = getJacobsthal(jacobsthalIndex);
		pendIndexIt = std::find(pendIndexes.rbegin(), pendIndexes.rend(), jacobsthal * -1);
		if (pendIndexIt == pendIndexes.rend())
		{
			pendIndexIt--;
		}

		int	counter = 0;
		for (; pendIndexIt != pendIndexes.rend(); ++pendIndexIt)
		{
			std::cout << inserted << std::endl;
			std::cout << "PENDINDEX IT: " << *pendIndexIt << std::endl;
			std::cout << "OFFSET CHAUFLAN: " << ((((*pendIndexIt) * -1) - inserted) * lastPairSize) + lastPairSize - 1 << std::endl;
			pendIt = pend.begin() + ((((*pendIndexIt) * -1) - inserted) * lastPairSize) + lastPairSize - 1;
			boundMain = std::find(mainIndexes.begin(), mainIndexes.end(), (*pendIndexIt) * -1);
			insertionIt = std::upper_bound(pairBounds.begin(), pairBounds.begin() + (boundMain - mainIndexes.begin()), *pendIt);
			// std::cout << "Bound main in mainIndexes: " << *(pairBounds.begin() + (boundMain - mainIndexes.begin())) << std::endl;
			// std::cout << "Pend ite: " << *pendIt << " | Bound Main: " << *boundMain << " | Insertion: " << *insertionIt << std::endl;
			this->print("Bounds", pairBounds);
			pairBounds.insert(insertionIt, *pendIt);
			insertionIt = std::find(pairBounds.begin(), pairBounds.end(), *pendIt);
			this->print("Bounds", pairBounds);
			// std::cout << "Hola?: " << (insertionIt - pairBounds.begin()) << std::endl;
			int	offset = (insertionIt - pairBounds.begin()) * lastPairSize;
			std::cout << "Offset: " << offset << std::endl;
			std::cout << "Pair limits: " << *(this->vec.begin() + offset) << std::flush << " | " << *(this->vec.begin() + offset + lastPairSize) << std::endl;
			this->vec.insert(this->vec.begin() + offset, pendIt - lastPairSize + 1, pendIt + 1);
			this->print("PEEEEEEEENED", pend);
			if (pend.end() == pendIt + 1)
				std::cout << "SAME" << std::endl;
			std::cout << "First: " << *(pendIt - lastPairSize + 1) << std::flush << " | Last: " << *(pendIt) << std::endl;
			pend.erase(pendIt - lastPairSize + 1, pendIt + 1);
			mainIndexes.insert(mainIndexes.begin() + (offset / lastPairSize), *pendIndexIt);
			pendIndexes.erase((pendIndexIt + 1).base());
			std::cout << "---" << std::endl;
			this->print("Main vector", this->vec);
			this->print("Pend vector", pend);
			this->print("Main indexes", mainIndexes);
			this->print("Pend indexes", pendIndexes);
			this->print("Bounds", pairBounds);
			counter++;
			std::cout << "---" << std::endl;
		}
		inserted += counter;
		std::cout << "Exiting jacobsthal" << std::endl;
		jacobsthalIndex++;
	}

	std::cout << std::endl;
}

void	PmergeMe::sort(int recursionLevel)
{
	std::cout << "Rec: " << recursionLevel << std::endl;
	std::size_t	elementsAmount = 2 << (recursionLevel - 1);
	if (this->vec.size() <= elementsAmount)
		return ;

	std::size_t	lastPairSize = elementsAmount >> 1;
	std::size_t	legalElements = (this->vec.size() / elementsAmount) * elementsAmount;
	std::cout << "Legal elements sorting: " << legalElements << std::endl;
	for (std::size_t i = lastPairSize - 1; i < legalElements; i += elementsAmount)
	{
		std::cout << "Iteration: " << i << std::endl;
		if (this->vec.at(i) < this->vec.at(i + lastPairSize))
			continue ;

		for (int j = lastPairSize - 1; j >= 0; j--)
		{
			int	&firstNumber = this->vec.at(i - j);
			int	&secondNumber = this->vec.at(i - j + lastPairSize);
			std::swap(firstNumber, secondNumber);
		}
	}
	this->print("", this->vec);
	this->sort(recursionLevel + 1);
	std::cout << std::endl;
	this->insertMerge(recursionLevel, elementsAmount, lastPairSize);
}

void	PmergeMe::sortMergeInsertAlgorithm(int *numbers, int size)
{
	this->vec = std::vector<int>(numbers, numbers + size);
	this->print("Main vec", this->vec);
	this->sort(1);
	this->print("Sorted main vec", this->vec);
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
