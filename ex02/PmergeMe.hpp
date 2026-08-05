#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::list<int> _list;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		class ErrorException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif