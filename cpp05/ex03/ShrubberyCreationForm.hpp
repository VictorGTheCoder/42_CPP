#ifndef ShrubberyForm
#define ShrubberyForm

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &f);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &f);
};

#endif
