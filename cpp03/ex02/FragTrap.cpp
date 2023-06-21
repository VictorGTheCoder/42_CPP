#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{std::cout << "FragTrap Default constructor called\n";}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{std::cout << "FragTrap name constructor called\n";}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_attackDamage = src._attackDamage;
	this->_energyPoints = src._energyPoints;
	this->_hitPoint = src._hitPoint;
	this->_name = src._name;
}

FragTrap::~FragTrap()
{std::cout << "FragTrap destructor called\n";}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        _name = src._name;
		_energyPoints = src._energyPoints;
		_hitPoint = src._hitPoint;
		_attackDamage = src._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " asked for a high five\n";
}