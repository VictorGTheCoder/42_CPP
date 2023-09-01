#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &inputfile);
		~BitcoinExchange();

		void readData(void);
		float getBitcointPriceAtDate(const std::string &date);
		bool isValidDate(const std::string &date);
		void readFileAndProcess();

	private:
		std::map<std::string, float> _rates;
		const std::string _inputfile;
};



#endif