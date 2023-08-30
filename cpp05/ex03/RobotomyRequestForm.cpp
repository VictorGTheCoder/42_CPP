#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	setTarget("Default target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) : AForm(f)
{
	setTarget(f.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (isSigned() == false)
    {
        throw (AForm::FormNotSignedException());
    }
    else if (executor.getGrade() > getExecGrade())
    {
        throw (AForm::GradeTooLowException());
    }
    else
    {
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
        std::cout << "BRRRRRR... BRRRR... VRRRR..." << std::endl; // Bruits de perceuse
		srand(time(NULL));
        if (rand() % 2) // 50% de chance de succès
        {
            std::cout << getTarget() << " has been robotomized successfully." << std::endl;
        }
        else
        {
            std::cout << "Robotomization of " << getTarget() << " failed." << std::endl;
        }
    }
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
    if (this == &f)
        return *this;
    AForm::operator=(f);
    return *this;
}
