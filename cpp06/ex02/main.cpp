#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int roll(int min, int max)
{
	
	srand(clock());

	int randNum = (rand() % max) + min;
	return (randNum);
}

Base* generate()
{
	int r;
	r = roll(0,3);
	switch (r)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void identify(Base* p) 
{
	std::cout << "Identify with pointer" << std::endl;
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identify with ref" << std::endl;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Error can't cast p in A, B or C" << std::endl;
			}
		}
	}		
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete (base);
	return 0;
}
