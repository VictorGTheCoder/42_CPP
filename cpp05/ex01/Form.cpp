#include "Form.hpp"

Form::Form() : _name("smith"), _signed(false), _grade(150) {}

Form::Form(std::string name, bool isSigned, int grade) : _name(name), _signed(isSigned), _grade(grade)
{
    try
    {
        if (grade > 150)
        {
            throw std::runtime_error("Form::GradeTooLowException");
        }
        else if (grade < 1)
        {
            throw std::runtime_error("Form::GradeTooHighException");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::~Form() {}

void Form::beSigned(Bureaucrat b)
{
    if (this->_signed == false)
    {
        if (this->_grade >= b.getGrade())
        {
            this->_signed = true;
        }
        else
        {
            std::cout << "Grade is not high enough" << std::endl;
        }
    }
    else
    {
        std::cout << "Form has already been signed";
    }
}

std::string Form::getName()
{
    return _name;
}

bool        Form::isSigned()
{
    return _signed;
}

int         Form::getGrade()
{
    return _grade;
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
    o << "Form " << f.getName() << ": signed " << f.isSigned() << ", grade needed " << f.getGrade() << std::endl; 
    return o;
}