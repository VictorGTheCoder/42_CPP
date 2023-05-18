#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	//ClapTrap bob("Bob");
	//ScavTrap tod("Tod");
	FragTrap alice("Alice");

	/*tod.attack("Bob");
	bob.takeDamage(2);
	tod.guardGate();

	bob.attack("Tod");
	tod.takeDamage(3);

	tod.beRepaired(3);
	bob.beRepaired(2);*/

	alice.highFivesGuys();
	alice.attack("Alice");
	alice.takeDamage(30);
	alice.beRepaired(10);
	return 0;
}
