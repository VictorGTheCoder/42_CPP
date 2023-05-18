#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "<------ Constructor ----->" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	std::cout << "<-------- TESTS ------->" << std::endl;

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

	std::cout << "<------ Destructor ------>" << std::endl;

    delete meta;
    delete j;
    delete i;

	std::cout << "<------ Constructor ----->" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

	std::cout << "<-------- TEST -------->" << std::endl;


    std::cout << wrongI->getType() << std::endl;
    wrongI->makeSound();

	std::cout << "<------ Destructor ------>" << std::endl;

    delete wrongMeta;
    delete wrongI;

    return 0;
}
