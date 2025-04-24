#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>

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

void	PmergeMe::insertMerge(int recursionLevel, int elementsAmount, int lastPairSize)
{
	(void) recursionLevel;
	(void) elementsAmount;
	(void) lastPairSize;
}

void	PmergeMe::sort(int recursionLevel)
{
	std::cout << "Rec: " << recursionLevel << std::endl;
	std::size_t	elementsAmount = 2 << (recursionLevel - 1);
	if (this->vec.size() <= elementsAmount)
		return ;

	std::size_t	lastPairSize = elementsAmount >> 1;
	for (std::size_t i = lastPairSize - 1; this->vec.size() - i + 1 >= elementsAmount; i += elementsAmount)
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
	this->print();
	this->sort(recursionLevel + 1);
	this->insertMerge(recursionLevel, elementsAmount, lastPairSize);
}

void	PmergeMe::sortMergeInsertAlgorithm(int *numbers, int size)
{
	this->vec = std::vector<int>(numbers, numbers + size);
	this->print();
	this->sort(1);
	this->print();
}

void	PmergeMe::print()
{
	for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
