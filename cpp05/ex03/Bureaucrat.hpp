#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

        void    promote(int n);
        void    demote(int n);

        int getGrade() const;
        std::string const getName() const;
        void signForm(AForm &f);
        void executeForm(AForm &f);

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif