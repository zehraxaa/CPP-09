#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout<<"Error: Incorrect number of arguments"<<std::endl;
		return 1;
	}
	try
	{

	}
	catch(std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	return 0;
}