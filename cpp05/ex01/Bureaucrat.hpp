#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif