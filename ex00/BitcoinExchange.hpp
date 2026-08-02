#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _datab;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		class DataFileNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NegativeNumberException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class TooLargeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif