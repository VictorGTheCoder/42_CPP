#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "\n<------ Constructor -----> \n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	std::cout << "\n<-------- TESTS -------> \n" << std::endl;


    std::cout << "Type : " << j->getType() << std::endl;
    std::cout << "Type : " << i->getType() << "\n" << std::endl;
  
    i->makeSound();
    j->makeSound();
    meta->makeSound();

	std::cout << "\n<------ Destructor ------> \n" << std::endl;

    delete meta;
    delete j;
    delete i;

	std::cout << "\n<------ Constructor -----> \n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

	std::cout << "\n<-------- TEST --------> \n" << std::endl;

    std::cout << wrongI->getType() << std::endl;
    wrongI->makeSound();

	std::cout << "\n<------ Destructor ------> \n" << std::endl;

    delete wrongMeta;
    delete wrongI;

    return 0;
}
