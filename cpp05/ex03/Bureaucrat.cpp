#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Smith"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw std::runtime_error("Bureaucrat::GradeTooHighException");
        else if (grade > 150)
            throw std::runtime_error("Bureaucrat::GradeTooLowException");
        _grade = grade;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm &f)
{
    try
    {
        f.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Bureaucrat::promote(int n)
{
    try
    { 
        if (_grade - n < 1)
        {
            throw std::runtime_error("Bureaucrat::GradeTooHighException");
        }
        else
            _grade -= n;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::demote(int n)
{
    try
    {
        if (_grade + n > 150)
        {
            throw std::runtime_error("Bureaucrat::GradeTooLowException");
        }
        else
            _grade += n;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
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