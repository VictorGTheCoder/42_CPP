#include "Animal.hpp"

Animal::Animal() : _type("None")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &animal) : _type(animal._type)
{	
	std::cout << "Animal with type constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "An animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}