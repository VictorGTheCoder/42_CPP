#include "ScalarConverter.h"

void displayChar(char c)
{
	std::cout << "char: ";
	if (c < 0) //c > 127
		std::cout << "Impossible" << std::endl;
	else if (c < 32 ||  c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::display(char c)
{
	int i = static_cast<int>(c);
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);

    displayChar(c);
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;

}

void ScalarConverter::display(int n)
{
	char c = static_cast<int>(n);
	double d = static_cast<double>(n);
	float f = static_cast<float>(n);

    displayChar(c);

	

    std::cout << "int: " << n << std::endl;
	if (n == f && f < 1000000)
    	std::cout << "float: " << f << ".0f" << std::endl;
	else
    	std::cout << "float: " << f << "f" << std::endl;
	if (n == d && d < 1000000)
    	std::cout << "double: " << d << ".0" << std::endl;
	else
    	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::display(float n)
{
	char c = static_cast<int>(n);
	double d = static_cast<double>(n);
	int i = static_cast<int>(n);

    displayChar(c);
	if (n > INT_MAX)
		std::cout << "int : Impossible" << std::endl;
	else
    	std::cout << "int: " << i << std::endl;
	if (i == n && n < 1000000)
    	std::cout << "float: " << n << ".0f" << std::endl;
	else
    	std::cout << "float: " << n << "f" << std::endl;
	if (i == d && d < 1000000)
    	std::cout << "double: " << d << ".0" << std::endl;
	else
    	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::display(double n)
{
	char c = static_cast<int>(n);
	float f = static_cast<float>(n);
	int i = static_cast<int>(n);

    displayChar(c);
	if (n > INT_MAX)
		std::cout << "int : Impossible" << std::endl;
	else
    	std::cout << "int: " << i << std::endl;
	if (i == f && f < 1000000)
    	std::cout << "float: " << n << ".0f" << std::endl;
	else
    	std::cout << "float: " << n << "f" << std::endl;
	if (i == n && n < 1000000)
    	std::cout << "double: " << n << std::endl;
	else
    	std::cout << "double: " << n << std::endl;
	
}


void ScalarConverter::displayUnknown()
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;

}