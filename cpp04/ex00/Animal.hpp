#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal &animal);
		virtual ~Animal();
	
		Animal &operator=(const Animal &src);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
