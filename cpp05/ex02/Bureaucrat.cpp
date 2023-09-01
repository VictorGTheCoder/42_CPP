#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Smith"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b._name), _grade(b._grade) {}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(AForm &f)
{
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm &f)
{
    f.execute(*this);
}

void Bureaucrat::promote(int n)
{

    if (_grade - n < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
        _grade -= n;
}

void Bureaucrat::demote(int n)
{
    if (_grade + n > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
        _grade += n;
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string const Bureaucrat::getName() const
{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() << ", bureaucrate grade " << b.getGrade() << std::endl;
	return o;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
    {
        this->_grade = b._grade;
    }
    return *this;
}