#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout<<"Error: Incorrect number of arguments"<<std::endl;
		return 1;
	}
	BitcoinExchange obj;
	try
	{
		obj.processDataFile();
		obj.processInputFile(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
		return 1;
	}
	return 0;
}