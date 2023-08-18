
#include "ScalarConverter.h"


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
    std::string input = argv[1];

    // Conversion en char
	displayChar(input);












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

