#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

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

        int getGrade();
        std::string const getName();
        void signForm(Form f);

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif