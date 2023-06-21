#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &wrongAnimal)
{	
	*this = wrongAnimal;
	std::cout << "Animal copy consructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "wpahflwahlawgwabgwljghbawlgbaw" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}