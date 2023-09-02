#include "AForm.hpp"

AForm::AForm() : _name("smith"), _signed(false), _signGrade(150), _execGrade(100){}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    try
    {
        if (signGrade > 150)
        {
            throw AForm::GradeTooLowException();
        }
        else if (signGrade < 1)
        {
            throw AForm::GradeTooHighException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::AForm(const AForm &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade()) {}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat &b)
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
            throw AForm::GradeTooLowException();
        }
    }
    else
    {
        throw AForm::FormAlreadySignedException();
    }
}

std::string AForm::getName() const
{
    return _name;
}

bool        AForm::isSigned() const
{
    return _signed;
}

int         AForm::getSignGrade() const
{
    return _signGrade;
}

int         AForm::getExecGrade() const
{
    return _execGrade;
}

std::string AForm::getTarget(void) const
{
    return _target;
}

void       AForm::setTarget(std::string target)
{
    _target = target;
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
    o << "Form " << f.getName() << ": signed " << f.isSigned() << ", sign grade needed " << f.getSignGrade() << ", execution grade needed " << f.getExecGrade() << std::endl; 
    return o;
}


AForm& AForm::operator=(const AForm& f)
{
    if (this == &f)
        return *this;
    this->_signed = f._signed;
    this->_target = f._target;
    return *this;
}
