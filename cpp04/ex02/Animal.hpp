#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal &animal);
		virtual ~Animal();
	
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
