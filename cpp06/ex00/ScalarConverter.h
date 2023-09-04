#ifndef SCALAR
# define SCALAR

#include <climits>
#include <iostream>
#include <cstdlib>
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
		static void			convert(std::string input);
		static void			displayAll(void);
		static void			setString(const std::string &str);
		static DataType		getType(void);
		static std::string	getString(void);
		static void			setType(DataType type);
		static void 		determineType(void);
		static void			display(char c);
		static void			display(int n);
		static void			display(double n);
		static void			display(float n);
		static void			displayUnknown(void);


	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &s);
		~ScalarConverter();
		static std::string _str;
		static DataType _type;
};

#endif