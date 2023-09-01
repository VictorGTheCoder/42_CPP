
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) {setTarget("Target");}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5) {setTarget(target);}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f) : AForm(f)
{
	setTarget(f.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > getExecGrade())
		throw (AForm::GradeTooLowException());
	else
		std::cout << getTarget() << "has been pardonned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
    if (this == &f)
        return *this;

    AForm::operator=(f);


    return *this;
}