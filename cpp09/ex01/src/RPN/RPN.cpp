#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;

	this->operationsBuffer_ = other.operationsBuffer_;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::calculateRPN(const std::string &expression)
{
	(void) expression;
}
