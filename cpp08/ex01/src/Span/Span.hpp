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

	Span	&operator=(const Span &other);

	~Span();
};
