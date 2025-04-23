#include "RPN.hpp"
#include <iostream>

const std::string RPN::operands[OPERANDS_AMOUNT] = { "+", "-", "*", "/" };

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

bool	RPN::isNumber(const std::string &token)
{
	return std::isdigit(token[0]);
}

bool	RPN::isOperand(const std::string &token)
{
	const std::string	*operandsEnd = operands + OPERANDS_AMOUNT;
	return std::find(operands, operandsEnd, token) != operandsEnd;
}

int	RPN::operate(int lval, int rval, const std::string &token)
{
	if (token == "+") return lval + rval;
	if (token == "-") return lval - rval;
	if (token == "*") return lval * rval;
	if (token == "/") return lval / rval;
	return 0;
}

void	RPN::handleOperand(const std::string &operand)
{
	if (this->operationsBuffer_.size() < 2)
		throw std::invalid_argument("Insufficient numbers to compute '"
			+ operand + "' operation (Numbers amount = Operands amount - 1)");

	int	lval = 0, rval = 0;
	rval = this->operationsBuffer_.top();
	this->operationsBuffer_.pop();
	lval = this->operationsBuffer_.top();
	this->operationsBuffer_.pop();
	this->operationsBuffer_.push(this->operate(lval, rval, operand));
}

std::string	RPN::getToken(const std::string &expression, std::size_t &startPos)
{
	while (startPos < expression.size() && expression[startPos] == ' ')
		startPos++;

	std::size_t	nextSeparator = expression.find(' ', startPos);
	std::string	token = expression.substr(startPos, nextSeparator - startPos);
	startPos += token.length();

	if (token.empty())
		return token;
	if (token.length() != 1 || (!this->isNumber(token) && !this->isOperand(token)))
		throw std::invalid_argument("Invalid token: " + token);
	return token;
}

void	RPN::calculateRPN(const std::string &expression)
{
	std::size_t	pos = 0;
	std::string	token;

	do
	{
		token = getToken(expression, pos);

		if (this->isNumber(token))
			this->operationsBuffer_.push(std::atoi(token.c_str()));
		else if (this->isOperand(token))
			this->handleOperand(token);
	} while (pos < expression.size() && !token.empty());

	if (this->operationsBuffer_.size() != 1)
		throw std::invalid_argument("Too many numbers (Numbers amount = Operands amount - 1)");
	std::cout << this->operationsBuffer_.top() << std::endl;
}
