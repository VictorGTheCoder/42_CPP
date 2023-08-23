#include "ScalarConverter.h"

void ScalarConverter::convert(std::string input)
{
    ScalarConverter::setString(input);

    ScalarConverter::determineType();

    DataType t = ScalarConverter::getType();
    if (t == INT)
        std::cout << "INT" << std::endl;
    if (t == FLOAT)
        std::cout << "FLOAT" << std::endl;
    if (t == DOUBLE)
        std::cout << "DOUBLE" << std::endl;
    if (t == UNKNOWN)
        std::cout << "UNKNOWN" << std::endl;        
    //std::cout << t << std::endl;
    if (t == UNKNOWN)
        return ;
}


void ScalarConverter::displayAll()
{
    std::cout << "char: " << "'" << _c << "'" << std::endl;
    std::cout << "int: " << ScalarConverter::_nb << std::endl;
    std::cout << "float: " << _nb_f << "f" << std::endl;
    std::cout << "double: " << _nb_d << std::endl;
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


    // Check if string is an integer
    char* end;
    strtol(str.c_str(), &end, 10);
        // Check for double
    std::istringstream issDouble(str);
    double d;
    issDouble >> d;
    // Check for float (ending in 'f' or 'F')
    if (str[str.size() - 1] == 'f' || str[str.size() - 1] == 'F') {
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
}