#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
	private:
		std::stack<int> postfix;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void parseArgument(const std::string& input);

		class ErrorException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif