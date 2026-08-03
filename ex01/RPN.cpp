#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : postfix(other.postfix) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->postfix = other.postfix;
	return *this;
}

RPN::~RPN() {}

void RPN::parseArgument(const std::string& input)
{
	if (input.empty())
		throw ErrorException();

	std::istringstream iss(input);
	std::string token;
	int oprt = 0;

	while (iss >> token)
	{
		if (token.length() != 1)
			throw ErrorException();

		char c = token[0];

		if (c >= '0' && c <= '9')
			postfix.push(c - '0');

		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			oprt++;

			if (postfix.size() < 2)
				throw ErrorException();

			int b = postfix.top();
			postfix.pop();
			int a = postfix.top();
			postfix.pop();

			if (c == '/' && b == 0)
				throw ErrorException();

			int result = 0;
			if      (c == '+')
				result = a + b;
			else if (c == '-')
				result = a - b;
			else if (c == '*')
				result = a * b;
			else if (c == '/')
				result = a / b;

			postfix.push(result);
		}
		else
			throw ErrorException();
	}
	if (postfix.size() != 1 || oprt == 0)
		throw ErrorException();

	std::cout << postfix.top() << std::endl;
}

const char * RPN::ErrorException::what() const throw()
{
	return "Error";
}