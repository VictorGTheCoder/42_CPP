#ifndef SCALAR
# define SCALAR

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <cstdlib> // for atoi, atof
#include <sstream> 

enum DataType {
    INT,
    FLOAT,
    DOUBLE,
	CHAR,
    UNKNOWN
};

class ScalarConverter 
{
	public:
		static void	convert(const std::string& input);
		void		setString(const std::string &str);
		DataType	getType(void);
		void		setType(DataType type);
		void 		determineType(void);
	private:
		std::string _str;
		DataType _type;

};


#endif