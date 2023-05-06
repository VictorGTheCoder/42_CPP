#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Zombie zombie1("Paulo1");
    Zombie* zombie2 = newZombie("Paulo2");

    zombie1.announce();
    zombie2->announce();

    delete (zombie2);
    return 0;
}
