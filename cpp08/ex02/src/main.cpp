#include "MutantStack/MutantStack.hpp"
#include <list>
#include <vector>
#include <iostream>

void	testSujectMS()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	stack(mstack);
}

void	testSujectVector()
{
	std::vector<int>	vec;

	vec.push_back(5);
	vec.push_back(17);

	std::cout << vec.back() << std::endl;

	vec.pop_back();

	std::cout << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	//[...]
	vec.push_back(0);

	std::vector<int>::iterator	it = vec.begin();
	std::vector<int>::iterator	ite = vec.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::vector<int>	vec2(vec);
}

void	testSujectList()
{
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator	it = list.begin();
	std::list<int>::iterator	ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>	list2(list);
}

void	testExtra()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(737);

	MutantStack<int>	mstack2(mstack);
	MutantStack<int>::iterator	it = mstack2.begin();
	MutantStack<int>::iterator	ite = mstack2.end();

	for (; it != ite; ++it)
	{
		std::cout << *it << std::endl;
	}

	const MutantStack<int>				cstack = mstack;
	MutantStack<int>::const_iterator	cit = cstack.begin();
	MutantStack<int>::const_iterator	cite = cstack.end();

	// *cit = 3;
	for (; cit != cite; ++cit)
	{
		std::cout << *cit << std::endl;
	}
}

int	main()
{
	testSujectMS();
	std::cout << std::endl;
	testSujectVector();
	std::cout << std::endl;
	testSujectList();
	std::cout << std::endl;
	testExtra();
	return 0;
}
