#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    PmergeMe *m = new PmergeMe(argv);  


    std::cout << "Vector" << std::endl;
    std::cout << "Before: ";
    m->displayVector();
    m->mergeInsertSortWithVector();   
    std::cout << "After: ";
    m->displayVector();


    std::cout << "List" << std::endl;
    std::cout << "Before: ";
    m->displayList();
    m->mergeInsertSortWithList();
    std::cout << "After: ";
    m->displayList();

    delete(m);
    return 0;
}