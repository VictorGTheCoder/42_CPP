
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
    ScalarConverter::convert(input);

    return 0;
}

