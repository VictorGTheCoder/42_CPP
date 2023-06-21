#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	
public:
	WrongCat();
	WrongCat(WrongCat &src);
	~WrongCat();

	WrongCat &operator=(const WrongCat &src);
	
	void makeSound() const;
};



#endif