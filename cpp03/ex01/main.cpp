#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");
	ScavTrap tod("Tod");

	tod.attack("Bob");
	bob.takeDamage(2);
	tod.guardGate();

	bob.attack("Tod");
	tod.takeDamage(3);

	tod.beRepaired(3);
	bob.beRepaired(2);
	return 0;
}
