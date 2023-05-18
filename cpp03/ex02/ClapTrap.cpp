#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("noName"), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{std::cout << "ClapTrap Default constructor called\n";}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{std::cout << "ClapTrap Name constructor called\n";}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoints, unsigned int attackDamage) : _name(name), _hitPoint(hitPoint), _energyPoints(energyPoints), _attackDamage(attackDamage)
{std::cout << "ClapTrap full constructor called\n";}

ClapTrap::~ClapTrap(void)
{std::cout << "ClapTrap Destructor called\n";}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap : " << _name << " has not enough hit points to attack !\n";
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap : " <<  _name << " attacked " << target << " causing " << _attackDamage << " points of damage! " << _name << " has " << _energyPoints <<" energy points\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint == 0)
	{
		std::cout << _name << " is already dead\n";
		return ;
	}
	if ((int)_hitPoint - (int)amount < 0)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	std::cout << _name << " has taken " << amount << " damage! " << _name << " has " << _hitPoint << " hp\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << _name << " has not enough energy to be repaired!\n";
		return ;
	}
	_hitPoint += amount;
	_energyPoints--;
	std::cout << _name << " has been rapaired for " << amount << " hp! " << _name << " has " << _energyPoints << " energy points and " << _hitPoint << " hp\n";
}