#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool   _signed;
        const int _grade;   
    public:
        Form();
        Form(std::string name, bool isSigned, int grade);
        ~Form();

        void beSigned(Bureaucrat b);
        std::string getName();
        bool        isSigned();
        int         getGrade();
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif