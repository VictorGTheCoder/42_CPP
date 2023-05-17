#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap;
	ClapTrap clapclap("Bob");

	clap.attack("Bob");
	clapclap.attack("noName");

	clapclap.beRepaired(199);
	clapclap.takeDamage(1);
	clapclap.takeDamage(300);
	clapclap.beRepaired(199);

	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");
	clap.attack("Bob");

	return 0;
}
