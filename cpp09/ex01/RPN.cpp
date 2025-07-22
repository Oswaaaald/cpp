#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy) : _stack(copy._stack)
{
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		this->_stack = copy._stack;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string &sign) const
{
	if (sign == "+" || sign == "-" || sign == "*" || sign == "/")
		return true;
	return false;
}

void RPN::applyOperator(const std::string &sign)
{
	if (this->_stack.size() < 2)
		throw std::runtime_error("Error");

	int b = this->_stack.top();
	this->_stack.pop();
	int a = this->_stack.top();
	this->_stack.pop();

	if (sign == "+")
		this->_stack.push(a + b);
	else if (sign == "-")
		this->_stack.push(a - b);
	else if (sign == "*")
		this->_stack.push(a * b);
	else if (sign == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error");
		this->_stack.push(a / b);
	}
}

int RPN::compute(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string sign;

	while (iss >> sign)
	{
		if (isOperator(sign))
			this->applyOperator(sign);
		else
		{
			char *end;
			int value = std::strtol(sign.c_str(), &end, 10);
			if (*end || value < 0 || value > 9)
				throw std::runtime_error("Error");
			this->_stack.push(value);
		}
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("Error");
	return this->_stack.top();
}
