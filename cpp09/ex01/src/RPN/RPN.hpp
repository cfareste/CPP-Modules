#pragma once

#include <stack>

class RPN
{
private:
	std::stack<int>	operationsBuffer_;

public:
	RPN();
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);
	~RPN();

	void	calculateRPN(const std::string &expression);
};
