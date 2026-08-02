#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _datab(other._datab) {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_datab = other._datab;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processDataFile()
{
	std::fstream dataFile;

	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw DataFileNotFoundException();

	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		size_t comma = line.find(',');
		std::string date = line.substr(0, comma);
		float rate = std::atof(line.substr(comma + 1).c_str());
		_datab[date] = rate;
	}
	dataFile.close();
}

void BitcoinExchange::processInputFile(std::string input)
{
	std::fstream inputFile;

	inputFile.open(input.c_str());
	if (!inputFile.is_open())
		throw BadInputFileException();
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout<<"Error: bad input => "<<line<<std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe-1);
		std::string valueStr = line.substr(pipe+2);
		if (!isValidDate(date))
		{
			std::cout<<"Error: bad input => "<<line<<std::endl;
			continue;
		}
		float value;
		if (!isValidValue(valueStr, value))
			continue;
		std::map<std::string, float>::const_iterator it = _datab.upper_bound(date);
		if (it == _datab.begin())
		{
			std::cout<<"Error: no data for this date."<<std::endl;
			continue;
		}
		it--;
		std::cout<<date<<" => "<<value<<" = "<<(value * it->second)<<std::endl;
	}
	inputFile.close();
}

const char* BitcoinExchange::DataFileNotFoundException::what() const throw()
{
	return "Error: data.csv file could not found";
}

const char* BitcoinExchange::BadInputFileException::what() const throw()
{
	return "Error: Bad Input file format";
}