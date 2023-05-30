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
	ClapTrap(const ClapTrap &src);
	ClapTrap(std::string name);
	~ClapTrap(void);

	ClapTrap &operator=(const ClapTrap &src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int	getAttackDamage();
	unsigned int	getHitPoint();
	unsigned int	getEnergyPoints();
	std::string		getName();

	void setAttackDamage(unsigned int n);
	void setHitPoint(unsigned int n );
	void setEnergyPoints(unsigned int n);
	void setName(std::string name);
};

#endif