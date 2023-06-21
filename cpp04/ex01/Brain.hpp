#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define NUMBERS_OF_IDEAS 100

class Brain
{
	private:
		std::string _ideas[NUMBERS_OF_IDEAS];
	public:
		Brain();
		Brain(Brain &src);
		~Brain();

		Brain &operator=(const Brain &src);
		
		std::string getIdea(int index);
		void 		setIdea(int index, std::string idea);
};

#endif