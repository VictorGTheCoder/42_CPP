#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &inputfile) : _inputfile(inputfile) {}

BitcoinExchange::~BitcoinExchange() {}


std::string build_date(int day, int month, int year)
{
	std::stringstream str;
	str << year;
	str << '-';
	if (month < 10)
		str << '0';
	str << month;
	str << '-';
	if (day < 10)
		str << '0';
	str << day;
	return (str.str());
}

bool isStringFormatCorrect(const std::string &str)
{
    std::string::const_iterator it = str.begin();
	int count = 0;
    while (it != str.end() && (std::isdigit(*it) || *it == '-')) {
        if (*it == '-')
			count ++;
		it++;
    }
	if (count != 2)
		return false;
    return !str.empty() && it == str.end();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int year;
	int month;
	int day;
	char sep = '-';
	if (isStringFormatCorrect(date) == false)
	{
		//std::cout << "Date contains illegal char" << std::endl;
 		return (false);
	}
	std::stringstream test(date);
	std::string yearStr, monthStr, dayStr;

	getline(test, yearStr, sep);
	getline(test, monthStr, sep);
	getline(test, dayStr);


    std::stringstream(yearStr) >> year;
    std::stringstream(monthStr) >> month;
    std::stringstream(dayStr) >> day;

	//std::cout << "Year: " << year << " Month: " << month << " Day: " << day << std::endl;
	if (month < 1 || month > 12)
	{
		//std::cerr << "Date format is not Valid" << std::endl;
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (year % 400 == 0 || (year % 100 != 0 && year	 % 4 == 0)) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) 
	{
		//std::cerr << "This day never existed" << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::readData()
{
	std::ifstream db("data.csv");
	if (!db.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return ;
	}
	std::string line;
	std::string db_date;
	while (std::getline(db, line))
	{
		// if (line.empty())
		// 	continue;
		std::istringstream sstream(line);
		std::string value;
		std::vector<std::string> values;
		while (std::getline(sstream, value, ','))
		{
			values.push_back(value);
		}
		_rates[values[0]] = std::atof(values[1].c_str());
	}

}

float BitcoinExchange::getBitcointPriceAtDate(const std::string &date)
{
	readData();
	std::map<std::string, float>::const_iterator it = _rates.find(date);
	if (it == _rates.end())
	{
		it = _rates.lower_bound(date);
		--it;
	}
	return it->second;
}

void BitcoinExchange::readFileAndProcess()
{
	std::ifstream infile(_inputfile.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return;
	}
	
	std::string line;
	while (std::getline(infile, line))
	{
		/*if (line.empty())
			continue;*/
		std::istringstream sstream(line);
		std::string value;
		std::vector<std::string> values;

		while (std::getline(sstream, value, '|'))
		{
			values.push_back(value);
		}

		if (values.size() < 2) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidDate(values[0].substr(0, values[0].size() - 1)))
			continue;

		float btcnb = std::atof(values[1].c_str());
		if (btcnb < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (btcnb > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::cout << values[0] << "=>" << values[1] << " = " << btcnb * getBitcointPriceAtDate(values[0]) << std::endl;
	}
}

