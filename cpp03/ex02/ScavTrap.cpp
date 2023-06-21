#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	
	std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_attackDamage = src._attackDamage;
	this->_energyPoints = src._energyPoints;
	this->_hitPoint = src._hitPoint;
	this->_name = src._name;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
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

void ScavTrap::guardGate(void)
{
	std::cout << _name << " is now in gate keeper mode \n";
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " has not enough energy points to attack !\n";
	else if (_hitPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " has 0 hp, therefore he cannot attack !\n";
	}
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " <<  _name << " attacked " << target << " causing " << _attackDamage << " points of damage! He has " << _energyPoints <<" energy points\n";
	}
}