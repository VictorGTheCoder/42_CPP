#ifndef SCALAR
# define SCALAR

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		
	public:
		void convert(std::string str);
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		~ScalarConverter();
};



#endif