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
		std::string	_c;
		std::string	_nb;
		std::string	_nbf;
		std::string	_nbd;
		static void			convert(std::string input);
		static void			displayAll(void);
		static void			setString(const std::string &str);
		static DataType		getType(void);
		static std::string	getString(void);
		static void			setType(DataType type);
		static void 		determineType(void);

	private:
		std::string _str;
		DataType _type;



};


#endif