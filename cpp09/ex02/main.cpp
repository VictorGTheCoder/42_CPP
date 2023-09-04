#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    PmergeMe *m = new PmergeMe(argv);  


    m->mergeInsertSort();

    
    delete(m);
    return 0;
}