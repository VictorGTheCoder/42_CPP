#include "ScalarConverter.h"

void ScalarConverter::convert(const std::string& input)
{
	(void) input;
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

void ScalarConverter::determineType(void)
{
	std::string str = _str;
    // Check if string is an integer
    char* end;
    strtol(str.c_str(), &end, 10);
    if (*end == '\0') setType(INT);

    // Check for float (ending in 'f' or 'F')
    if (str[str.size() - 1] == 'f' || str[str.size() - 1] == 'F') {
        std::istringstream iss(str);
        float f;
        iss >> f;
        if (!iss.fail() && iss.eof()) setType(FLOAT);
    }

    // Check for double
    std::istringstream issDouble(str);
    double d;
    issDouble >> d;
    if (!issDouble.fail() && issDouble.eof())  setType(DOUBLE);

    setType(UNKNOWN);;
}