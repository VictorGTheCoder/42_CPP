#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("noName"), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{std::cout << "ClapTrap Default constructor called\n";}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{std::cout << "ClapTrap Name constructor called\n";}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoints, unsigned int attackDamage) : _name(name), _hitPoint(hitPoint), _energyPoints(energyPoints), _attackDamage(attackDamage)
{std::cout << "ClapTrap full constructor called\n";}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called" << std::endl;
	this->_attackDamage = src._attackDamage;
	this->_energyPoints = src._energyPoints;
	this->_hitPoint = src._hitPoint;
	this->_name = src._name;
}

ClapTrap::~ClapTrap(void)
{std::cout << "ClapTrap Destructor called\n";}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has not enough energy points to attack !\n";
	else if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " has 0 hp, therefore he cannot attack !\n";
	}
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " <<  _name << " attacked " << target << " causing " << _attackDamage << " points of damage! He has " << _energyPoints <<" energy points\n";
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

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
		_energyPoints = rhs._energyPoints;
		_hitPoint = rhs._hitPoint;
		_attackDamage = rhs._attackDamage;
    }
    return *this;
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

unsigned int	ClapTrap::getHitPoint()
{
	return (this->_hitPoint);
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

std::string ClapTrap::getName()
{
	return (this->_name);
}

void ClapTrap::setAttackDamage(unsigned int n)
{
	this->_attackDamage = n;
}

void	ClapTrap::setHitPoint(unsigned int n)
{
	this->_hitPoint = n;
}

void	ClapTrap::setEnergyPoints(unsigned int n)
{
	this->_energyPoints = n;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}
