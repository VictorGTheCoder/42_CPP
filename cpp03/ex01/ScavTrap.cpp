#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	
	std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << _name << " is now in gate keeper mode \n";
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
		std::cout << "ScavTrap : " << _name << " has not enough hit points to attack !\n";
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap : " <<  _name << " attacked " << target << " causing " << _attackDamage << " points of damage! He has " << _energyPoints <<" energy points\n";
	}
}