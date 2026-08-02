#include "BitcoinExchange.hpp"

const char* BitcoinExchange::DataFileNotFoundException::what() const throw()
{
	return "Error: data.csv file could not found";
}