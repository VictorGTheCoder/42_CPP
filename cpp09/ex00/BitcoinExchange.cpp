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

float BitcoinExchange::getBitcointPriceAtData(const std::string &date)
{
	(void) date;

	std::ifstream db("data.csv");

	if (!db.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return (-1);
	}

	std::string new_date = build_date(_day, _month, _year);


	std::string line;
	std::string db_date;
	while (std::getline(db, line))
	{
		int temp_day = _day;
		int temp_month = _month;
		int temp_year = _year;
		int i = 0;
		while (i < 4)
		{
			std::istringstream sstream(line);
			std::string value;
			std::vector<std::string> values;
			while (std::getline(sstream, value, ','))
				values.push_back(value);
			std::cout << "New date " << new_date << "|" << values[0] << std::endl;
			//std::cout << values[0] << " and " << "|" << new_date << "|" << std::endl;
			if (values[0] == new_date)
				return std::atof(values[1].c_str());
			if (temp_day > 1)
				temp_day--;
			else if (temp_month > 1)
			{
				temp_day = 31;
				temp_month--;
			}
			else
			{
				temp_day = 31;
				temp_month = 12;
				temp_year--;
			}
			new_date = build_date(temp_day, temp_month, temp_year);
			i++;
		}

	}

	return -0.1f;
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
	char sep = '-';
	if (isStringFormatCorrect(date) == false)
	{
		std::cout << "Date contains illegal char" << std::endl;
 		return (false);
	}
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