#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << ": Braiiiiiiinnnzzz" << std::endl;
}

Zombie::Zombie(std::string name)
{
    std::cout << "Create " << name << std::endl;
    _name = name;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroy " << _name << std::endl;
}