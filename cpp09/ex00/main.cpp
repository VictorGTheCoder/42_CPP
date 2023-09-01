#include "BitcoinExchange.hpp"






int main(int argc, char const *argv[])
{
	
	if (argc != 2)
	{
		std::cerr << "Error: Usage ./btc <file>" << std::endl;
		return (-1);
	}
	BitcoinExchange btc(argv[1]);
	std::string date = "2009-01-01";
	if (btc.isValidDate(date))
	{
		std::cout << "Start Programm " << std::endl;
		try
		{
			btc.readFileAndProcess();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
		//std::cout << "Btc price at " << date << " is " << (float) btc.getBitcointPriceAtDate(date) << std::endl;
	}
	return 0;
}
