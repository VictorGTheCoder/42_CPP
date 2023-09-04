
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 50);
        AForm *f = new RobotomyRequestForm();
        AForm *f2 = new ShrubberyCreationForm("Garden");
        AForm *f3 = new PresidentialPardonForm();

        std::cout << "<-------- F1 -------->" << std::endl;
        a.signForm(*f);
        a.executeForm(*f);
        std::cout << "<-------- F2 -------->" << std::endl;
        a.signForm(*f2);
        a.executeForm(*f2);
        std::cout << "<-------- F3 -------->" << std::endl;
        a.signForm(*f3);
        a.executeForm(*f3);

        delete (f);
        delete (f2);
        delete (f3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
