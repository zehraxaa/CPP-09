#include "BitcoinExchange.hpp"
#include <cctype>
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

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
		if (date[i] != '-')
			return false;
		}
		else if (!(std::isdigit(date[i])))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int endDaysofMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeap)
		endDaysofMonth[1] = 29;
	if (day < 1 || day > endDaysofMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& val, float& rank) const
{
	char *end;
	rank = static_cast<float>(std::strtod(val.c_str(), &end));
	if (end == val.c_str() || *end != '\0')
		return false;
	if (rank > 1000)
		return false;
	if (rank < 0)
		return false;
	return true;
}


void BitcoinExchange::processInputFile(std::string input)
{
	std::fstream inputFile;

	inputFile.open(input.c_str());
	if (!inputFile.is_open())
		throw BadInputFileException();
	std::string line;
	std::getline(inputFile, line);
	if (!line.empty() && line[line.size() - 1] == '\r')
		line.erase(line.size() - 1);
	if (line != "date | value")
	{
		inputFile.close();
		throw BadInputFileException();
	}
	while (std::getline(inputFile, line))
	{
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
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
		{
			std::cout<<"Error: bad input => "<<line<<std::endl;
			continue;
		}
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