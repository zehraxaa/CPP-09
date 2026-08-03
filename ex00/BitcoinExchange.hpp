#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
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

		void processDataFile();
		void processInputFile(std::string input);
		bool isValidDate(const std::string& date) const;
   		bool isValidValue(const std::string& val, float& rank) const;
    	void  printResult(const std::string& date, float value) const;
		class DataFileNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class BadInputFileException : public std::exception
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