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
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();

        void    promote(unsigned int n);
        void    demote(unsigned int n);

        int getGrade() const;
        std::string const getName() const;
        void signForm(AForm &f);
        void executeForm(AForm &f);


        Bureaucrat &operator=(Bureaucrat const &b);

        class GradeTooLowException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Grade to low to sign Form";
            }
        };
        class GradeTooHighException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Grade to high to sign Form";
            }
        };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif