
#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &f);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &f);
};



#endif