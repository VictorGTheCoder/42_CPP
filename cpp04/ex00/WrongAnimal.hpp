#ifndef WRONG_ANIMAL_CPP
# define WRONG_ANIMAL_CPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &src);
		
		void makeSound() const;
		std::string getType() const;
};


#endif