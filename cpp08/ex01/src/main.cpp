#include "Span/Span.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <list>

#ifndef SPAN_SIZE
# define SPAN_SIZE 1000000
#endif

void	subjectTest()
{
	std::cout << "SUBJECT TEST:" << std::endl;
	Span	span = Span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	std::cout << "SUBJECT TEST END\n" << std::endl;
}

void	fillTest()
{
	std::cout << "FILL TEST:" << std::endl;
	Span				span = Span(10);
	int					array[10] = { 51, 2, 33, 1, -5, 3, -2, -43, 90, 10 };
	std::vector<int>	numbers(array, array + 10);

	span.fill(numbers.begin(), numbers.end());
	span.listNumbers();

	std::cout << "Shortest filled span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest filled span: " << span.longestSpan() << std::endl;

	std::cout << "FILL TEST END\n" << std::endl;
}

void	mainTest()
{
	std::cout << "MAIN TEST:" << std::endl;
	Span	span = Span(SPAN_SIZE);
	int		biggestNum = 0;
	int		smallestNum = INT_MAX;

	std::srand(time(NULL));
	for (int i = 0; i < SPAN_SIZE; i++)
	{
		const int	num = static_cast<int>(std::rand() / static_cast<float>(RAND_MAX) * 1000000000) * (i & 1 ? 1 : -1);

		if (num > biggestNum)
			biggestNum = num;
		else if (num < smallestNum)
			smallestNum = num;
		span.addNumber(num);
		if (SPAN_SIZE <= 10)
			span.listNumbers();
	}

	std::cout << "Biggest in span: " << biggestNum << std::endl;
	std::cout << "Smallest in span: " << smallestNum << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	std::cout << "MAIN TEST END\n" << std::endl;
}

void	extraTest()
{
	std::cout << "EXTRA TEST:" << std::endl;
	Span				span = Span(5);
	int					array[5] = { 51, 17, 33, 1, -5 };

	span.fill(array, array + 5);
	span.listNumbers();

	try
	{
		span.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << "Error while adding number: " << e.what() << std::endl;
	}

	Span	span2 = Span(5);

	try
	{
		std::cout << span2.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while calculating shortest span: " << e.what() << std::endl;
	}

	Span	span3 = Span(5);

	try
	{
		span3.addNumber(6);
		std::cout << span3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while calculating longest span: " << e.what() << std::endl;
	}

	Span	span4 = Span(5);
	Span	span5 = Span(10);
	int		array2[10] = { 16, 23, 1, -32, 12, 51, 32 -43, 43, 7 };

	span4.fill(array, array + 5);
	span5.fill(array2, array2 + 10);
	Span	span6(span5);

	span4.listNumbers();
	span5.listNumbers();
	span6.listNumbers();

	std::cout << "Span4 shortest span: " << span4.shortestSpan() << std::endl;

	span5 = span4;

	try
	{
		std::cout << "New span5 shortest span: " << span5.shortestSpan() << std::endl;
		span5.listNumbers();
		span5.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << "Error while adding number: " << e.what() << std::endl;
	}

	Span	span7 = Span(5);

	span7.fill(array2, array2 + 2);
	span7.listNumbers();

	try
	{
		span7.fill(array + 2, array + 6);
		span7.listNumbers();
	}
	catch (std::exception &e)
	{
		std::cout << "Error while filling numbers: " << e.what() << std::endl;
	}
	std::cout << "EXTRA TEST END" << std::endl;
}

int	main()
{
	subjectTest();
	fillTest();
	mainTest();
	extraTest();
	return 0;
}
