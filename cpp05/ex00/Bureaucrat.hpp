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
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();

        void    promote(unsigned int n);
        void    demote(unsigned int n);

        int getGrade();
        std::string const getName();
        Bureaucrat &operator=(Bureaucrat const &b);

        class GradeTooLowException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Bureaucrat's grade can't be below 1";
            }
        };
        class GradeTooHighException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Bureaucrat's grade can't be above 150";
            }
        };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif