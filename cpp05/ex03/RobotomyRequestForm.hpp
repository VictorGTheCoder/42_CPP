#ifndef ROBOTOMYFORM_HPP
# define ROBOTOMYFORM_HPP

#include "AForm.hpp"



class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &f);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const &executor) const;
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &f);
};

#endif