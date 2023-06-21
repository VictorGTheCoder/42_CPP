#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	for (int i = 0; i < NUMBERS_OF_IDEAS; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index)
{
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > NUMBERS_OF_IDEAS)
	{
		std::cout << "Index out of range" << std::endl;
	}
	else
		_ideas[index] = idea;
}