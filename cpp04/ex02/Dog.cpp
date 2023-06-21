#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout << "Dog copy consructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return (*this);
	this->_type = dog._type;
	this->_brain = dog._brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "barks" << std::endl;
}
