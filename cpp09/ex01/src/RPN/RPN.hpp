#pragma once

#include <stack>
#include <string>

#define OPERANDS_AMOUNT 4

class RPN
{
private:
	const static std::string	operands[OPERANDS_AMOUNT];
	std::stack<float>			operationsBuffer_;

	bool		isNumber(const std::string &token);
	bool		isOperand(const std::string &token);
	float		operate(float lval, float rval, const std::string &token);
	void		handleOperand(const std::string &operand);
	std::string	getToken(const std::string &expression, std::size_t &startPos);

public:
	RPN();
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);
	~RPN();

	void	calculateRPN(const std::string &expression);
};
