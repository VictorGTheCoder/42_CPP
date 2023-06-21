#ifndef SCAV_TRAP_HPP
#	define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);

		ScavTrap &operator=(const ScavTrap &src);

		void guardGate();
		void attack(const std::string& target);
};

#endif