#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &inputfile);
		~BitcoinExchange();

		float getBitcointPriceAtData(const std::string &date);
		bool isValidDate(const std::string &date);

	private:

		int _day;
		int _month;
		int _year;
		const std::string _inputfile;
};



#endif