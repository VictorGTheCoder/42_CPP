
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1);
        Intern intern;

        AForm *form = intern.makeForm("robotomy request", "Boss");

        a.signForm(*form);
        a.executeForm(*form);

        
        form = intern.makeForm("robotomy", "Boss");
        form = intern.makeForm("robotomy", "Boss");


        delete (form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

