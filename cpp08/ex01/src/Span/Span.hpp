#pragma once

class Span
{
private:
	unsigned int	_size;
	unsigned int	_occupied;
	int				*_numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &other);

	void	addNumber(int num);
	int		shortestSpan() const;
	int		longestSpan() const;
	void	listNumbers() const;
	template<typename It>
	void	fill(It begin, It end);

	Span	&operator=(const Span &other);

	~Span();
};

#include "Span.tpp"
