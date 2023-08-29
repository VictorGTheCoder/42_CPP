#include "iter.hpp"

void increment(int &n)
{
	n++;
}

void to_upper(char &c)
{
	c = std::toupper(c);
}

int main()
{

	{
		char tab[] = "abcdefghi";
		int size = sizeof(tab) - 1;
		std::cout << tab << std::endl;

		iter(tab, size, to_upper); 
		
		std::cout << tab << std::endl;
	}

	{

		int tab[10] = {0,1,2,3,4,5,6,7,8,9};

		for (int i = 0; i < 10; i++)
		{
			std::cout << tab[i] << ", ";
		}
		std::cout << std::endl;

		iter(tab, 10, increment);

		for (int i = 0; i < 10; i++)
		{
			std::cout << tab[i] << ", ";
		}
		std::cout << std::endl;
	}
	return 0;

	
}


