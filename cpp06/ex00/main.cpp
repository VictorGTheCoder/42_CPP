
#include "ScalarConverter.h"


float stringToFloat(const std::string& s) {
    float result = 0.0f;
    int factor = 1;
    size_t i = 0;

    // Handle negative numbers
    if (s[0] == '-') {
        factor = -1;
        i = 1;
    }

    // Parse the integer part
    for (; i < s.size() && s[i] != '.'; i++) {
        result = result * 10 + (s[i] - '0');
    }

    // Parse the decimal part
    if (i < s.size() && s[i] == '.') {
        float decimalPlace = 0.1f;
        i++;
        for (; i < s.size(); i++) {
            result += (s[i] - '0') * decimalPlace;
            decimalPlace /= 10;
        }
    }

    return result * factor;
}

void displayChar(std::string s)
{
	int nb = atoi(s.c_str());
	if (s == "0")
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	if (nb == 0)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		std::cout << nb;
		std::cout << (char)(nb) << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
        return 1;
    }


    const char* s = "100.0f";


    std::stringstream ss1;

    ss1 << s;

    int tt = atoi(s);
    float result = stringToFloat(s);

    std::cout << tt << std::endl;
    std::cout << result << std::endl;











    std::string input = argv[1];
    ScalarConverter n;
    n.setString(input);

    n.determineType();

    DataType t = n.getType();
    if (t == INT)
        std::cout << "INT" << std::endl;
    if (t == FLOAT)
        std::cout << "FLOAT" << std::endl;
    if (t == DOUBLE)
        std::cout << "DOUBLE" << std::endl;
    if (t == UNKNOWN)
        std::cout << "UNKNOWN" << std::endl;        
    std::cout << t << std::endl;










/*
    // Conversion en int
	int i = atoi(input.c_str());
    if (i == 0 && input != "0") {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }

    // Conversion en float
    float f = atof(input.c_str());
    if (f == 0.0f && input != "0") {
        std::cout << "float: impossible" << std::endl;
    } else if (input == "nan" || input == "NaN") {
        std::cout << "float: nanf" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }

    // Conversion en double
    double d = atof(input.c_str());
    if (d == 0.0 && input != "0") {
        std::cout << "double: impossible" << std::endl;
    } else if (input == "nan" || input == "NaN") {
        std::cout << "double: nan" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
*/
    return 0;
}

