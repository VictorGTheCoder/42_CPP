#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &inputfile) : _inputfile(inputfile) {}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::getBitcointPriceAtData(const std::string &date)
{
	std::ifstream db("data.csv");

	if (!db.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return (-1);
	}

	std::string line;
	std::string db_date;
	while (std::getline(db, line))
	{
		std::istringstream sstream(line);
        std::string value;
        std::vector<std::string> values;
		while (std::getline(sstream, value, ','))
			values.push_back(value);
		if (values[0] == date)
			return std::atof(values[1].c_str());
	}
	return 0.0f;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	char sep = '-';
	std::stringstream test(date);
	std::string _yearStr, _monthStr, _dayStr;

	getline(test, _yearStr, sep);
	getline(test, _monthStr, sep);
	getline(test, _dayStr);


    std::stringstream(_yearStr) >> _year;
    std::stringstream(_monthStr) >> _month;
    std::stringstream(_dayStr) >> _day;

	std::cout << "Year: " << _year << " Month: " << _month << " Day: " << _day << std::endl;
	if (_month < 1 || _month > 12)
	{
		std::cerr << "Date format is not Valid" << std::endl;
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (_year % 400 == 0 || (_year % 100 != 0 && _year	 % 4 == 0)) {
        daysInMonth[2] = 29;
    }

    if (_day < 1 || _day > daysInMonth[_month]) 
	{
		std::cerr << "This day never existed" << std::endl;
		return false;
	}
	return true;
}