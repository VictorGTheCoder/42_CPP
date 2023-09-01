#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool   _signed;
        const int _signGrade;
        const int _execGrade;
        std::string _target;
    public:
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &f);
        virtual ~AForm();


		void			setTarget(std::string target);
		std::string		getTarget(void) const;
        void            beSigned(Bureaucrat &b);
        std::string     getName() const;
        bool            isSigned() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        virtual void    execute(Bureaucrat const & executor) const = 0;

        AForm &operator=(const AForm& f);

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
        class FormNotSignedException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Form is not signed";
            }
        };
        class FormAlreadySignedException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return "Form is already signed";
            }
        };
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif
