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

Form::Form(const Form &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade()){}

Form::~Form() {}

void Form::beSigned(Bureaucrat b)
{
    if (this->_signed == false)
    {
        if (this->_signGrade >= b.getGrade())
        {
            this->_signed = true;
            std::cout << b.getName() << " signed " << this->getName() << std::endl;
        }
        else
        {
            throw Form::GradeTooLowException();
        }
    }
    else
    {
        throw Form::FormIsAlreadySigned();
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

Form &Form::operator=(const Form &f)
{
    if (this != &f)
    {
        this->_signed = f._signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
    if (f.isSigned())
        o << "Form " << f.getName() << " is signed" << ", sign grade needed " << f.getSignGrade() << ", execution grade needed " << f.getExecGrade() << std::endl;
    else
        o << "Form " << f.getName() << " is not signed" << ", sign grade needed " << f.getSignGrade() << ", execution grade needed " << f.getExecGrade() << std::endl;
    return o;
}
