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

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::promote(unsigned int n)
{

    if (_grade - n < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
        _grade -= n;

}

void Bureaucrat::demote(unsigned int n)
{
    if (_grade + n > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
        _grade += n;
}

int Bureaucrat::getGrade()
{
    return (this->_grade);
}

std::string const Bureaucrat::getName()
{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() << ", bureaucrate grade " << b.getGrade();
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