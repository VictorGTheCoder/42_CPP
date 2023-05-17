#ifndef CLAP_TRAP_HPP
#	define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif