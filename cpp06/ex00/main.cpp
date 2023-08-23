
#include "ScalarConverter.h"


float stringToDouble(ScalarConverter n)
{
    std::string str = n.getString();
    DataType t = n.getType();
    if (t == DOUBLE || t == FLOAT)
    {
        std::istringstream issDouble(str);
        double d;
        issDouble >> d;
        return (d);
    }
    return (-166.66f);
}




int main(int argc, char const *argv[])
{
	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
        return 1;
    }


    std::string input = argv[1];




    //double d = stringToDouble(n);
    ScalarConverter::convert(input);
    //n.displayAll();










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

