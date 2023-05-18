#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{std::cout << "Default constructor called\n";}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{std::cout << "FragTrap name constructor called\n";}

FragTrap::~FragTrap()
{std::cout << "FragTrap destructor called\n";}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " asked for a high five\n";
}