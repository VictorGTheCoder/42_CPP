#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    PmergeMe *m = new PmergeMe(argv);  


    std::cout << "Vector" << std::endl;
    std::cout << "Not sorted" << std::endl;
    m->displayVector();
    m->mergeInsertSortWithVector();   
    std::cout << "Sorted" << std::endl;
    m->displayVector();


    std::cout << "List" << std::endl;
    std::cout << "Not Sorted" << std::endl;
    m->displayList();
    m->mergeInsertSortWithList();
    std::cout << "Sorted" << std::endl;
    m->displayList();

    delete(m);
    return 0;
}