#include "BitcoinExchange.hpp"



int main(int argc, char const *argv[])
{
	
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	BitcoinExchange btc(argv[1]);
	std::string date = "2021-08-26";
	if (btc.isValidDate(date))
		std::cout << "Btc price at " << date << " is " << (float) btc.getBitcointPriceAtData(date) << std::endl;
	return 0;
}
