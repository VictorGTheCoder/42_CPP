#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &i)
{
	(void) i;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &i)
{
	(void) i;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    struct FormCreator {
        std::string name;
        AForm *form;
    };
    FormCreator formCreators[] = {
        {"shrubbery creation", new ShrubberyCreationForm(formTarget)},
        {"robotomy request", new RobotomyRequestForm(formTarget)},
        {"presidential pardon", new RobotomyRequestForm(formTarget)}
    };

    for (size_t i = 0; i < sizeof(formCreators) / sizeof(FormCreator); i++)
    {
        if (formCreators[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i].form;
        }
    }
    throw FormNotFoundException();
    return NULL;
}
