#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{	
    std::cout << "<------ Constructor ----->" << std::endl;  

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const Animal* tabOfAnimals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            tabOfAnimals[i] = new Dog();
        else
            tabOfAnimals[i] = new Cat();
    }

    std::cout << "<--------- TEST --------->" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << tabOfAnimals[i]->getType() << " ";
        tabOfAnimals[i]->makeSound();
    }
        
    std::cout << "<------ ";
    
    std::cout << "<------ Destructor ------>" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        delete tabOfAnimals[i];
    }
    

    delete i;
    delete j;

    return 0;
}