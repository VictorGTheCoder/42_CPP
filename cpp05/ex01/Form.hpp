#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool   _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        Form();
        Form(std::string name, int grade);
        Form(const Form &f);
        ~Form();

        void beSigned(Bureaucrat b);
        std::string getName() const;
        bool        isSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        class GradeTooLowException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Form: Grade to low.";
            }
        };
        class GradeTooHighException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Form: Grade to high.";
            }
        };
};



std::ostream &operator<<(std::ostream &o, Form &f);

#endif