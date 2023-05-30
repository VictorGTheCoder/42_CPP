#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Create Zombie" << std::endl;

}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Create " << name << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroy " << _name << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": Braiiiiiiinnnzzz" << std::endl;
}
