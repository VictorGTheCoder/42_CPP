#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    std::cout << "Start Programm " << std::endl;

    PmergeMe *m = new PmergeMe(argv);  

    m->mergeInsertSort();

    delete(m);
    return 0;
}