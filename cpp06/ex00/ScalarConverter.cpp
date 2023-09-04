#include "ScalarConverter.h"

std::string ScalarConverter::_str;
DataType ScalarConverter::_type = UNKNOWN;

void ScalarConverter::convert(std::string input)
{
    ScalarConverter::setString(input);

    ScalarConverter::determineType();

    // DataType t = ScalarConverter::getType();
    // if (t == INT)
    //     std::cout << "INT" << std::endl;
    // if (t == CHAR)
    //     std::cout << "CHAR" << std::endl;
    // if (t == FLOAT)
    //     std::cout << "FLOAT" << std::endl;
    // if (t == DOUBLE)
    //     std::cout << "DOUBLE" << std::endl;
    // if (t == UNKNOWN)
    //     std::cout << "UNKNOWN" << std::endl;     
    displayAll();
}


void ScalarConverter::displayAll()
{
    const char *s = _str.c_str();
    char c = s[0];
    if (_type == CHAR)
        ScalarConverter::display(c);
    else if (_type == DOUBLE)
        ScalarConverter::display(std::atof(_str.c_str()));
    else if (_type == FLOAT)
        ScalarConverter::display(std::atof(_str.c_str()));
    else if (_type == INT)
        ScalarConverter::display(std::atoi(_str.c_str()));
    else if (_type == UNKNOWN)
        ScalarConverter::displayUnknown();
}


DataType ScalarConverter::getType(void)
{
	return _type;
}

void ScalarConverter::setType(DataType type)
{
	_type = type;
}



void ScalarConverter::setString(const std::string &str)
{
	_str = str;
}

std::string ScalarConverter::getString(void)
{
	return _str;
}

void ScalarConverter::determineType(void)
{
	std::string str = _str;


    char* end;
    strtol(str.c_str(), &end, 10);
    std::istringstream issDouble(str);
    double d;
    issDouble >> d;
    if (str.length() == 1 && std::isprint(str[0])) {
        if (std::isdigit(str[0]))
            setType(INT);
        else
            setType(CHAR);
    }
    else if (str[str.size() - 1] == 'f' || str[str.size() - 1] == 'F') {
        setType(FLOAT);
    }
    else if (*end == '\0')
    {
        setType(INT);

    }
    else if (!issDouble.fail() && issDouble.eof())
    {
        setType(DOUBLE);
    }
    else
    {
        setType(UNKNOWN);
    }
    if (d > INT_MAX || d < INT_MIN)
        setType(UNKNOWN);
}



ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter &s){(void) s;};

ScalarConverter::~ScalarConverter(){};
