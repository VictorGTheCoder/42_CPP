#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	
public:
	void makeSound() const;
	WrongCat();
	~WrongCat();
};

#endif