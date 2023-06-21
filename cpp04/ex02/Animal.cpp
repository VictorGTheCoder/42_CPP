#include "Animal.hpp"

Animal::Animal() : _type("None")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(Animal &animal)
{	
	*this = animal;
	std::cout << "Animal copy consructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "An animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}
