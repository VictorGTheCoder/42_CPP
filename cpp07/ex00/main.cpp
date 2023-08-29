#include "header.hpp"

int main()
{
	{
		int a = 1;
		int b = 2;
	
		std::cout << "a " << a << "   b " << b << std::endl;
		swap<int>(a, b);
		std::cout << "a " << a << "   b " << b << std::endl;
	}

	std::cout << "<------------------------------->" << std::endl;

	{
		std::string str1 = "Hello";
		std::string str2 = "Salut";


		std::cout << "a " << str1 << "   b " << str2 << std::endl;
		swap(str1, str2);
		std::cout << "a " << str1 << "   b " << str2 << std::endl;
	}

	std::cout << "<------------------------------->" << std::endl;

	{
		long nb1 = 1;
		long nb2 = 10;

		std::cout << "min = " << min(nb1, nb2) << std::endl;	
		std::cout << "max = " << min(nb1, nb2) << std::endl;		
	}	
	
	std::cout << "<------------------------------->" << std::endl;

	{
		char a = 'a';
		char b = 'b';

		std::cout << "min = " << min(a, b) << std::endl;	
		std::cout << "max = " << max(a, b) << std::endl;	
	}


	return 0;
}
