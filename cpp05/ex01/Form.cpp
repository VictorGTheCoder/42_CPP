#include "Form.hpp"

Form::Form() : _name("smith"), _signed(false), _signGrade(150), _execGrade(100){}

Form::Form(std::string name, int grade) : _name(name), _signed(false), _signGrade(grade), _execGrade(100)
{
    if (grade > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade())
{
}


Form::~Form() {}

void Form::beSigned(Bureaucrat b)
{
    if (this->_signed == false)
    {
        if (this->_signGrade >= b.getGrade())
        {
            this->_signed = true;
        }
        else
        {
            throw Form::GradeTooLowException();
        }
    }
    else
    {
        std::cout <<  this->getName() << " has already been signed" << std::endl;
    }
}

std::string Form::getName() const
{
    return _name;
}

bool        Form::isSigned() const
{
    return _signed;
}

int         Form::getSignGrade() const
{
    return _signGrade;
}

int         Form::getExecGrade() const
{
    return _execGrade;
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
    o << "Form " << f.getName() << ": signed " << f.isSigned() << ", sign grade needed " << f.getSignGrade() << ", execution grade needed " << f.getExecGrade() << std::endl; 
    return o;
}
