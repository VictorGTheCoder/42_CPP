#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;
    PmergeMe *m = new PmergeMe("1 2 3 6 5");  
    m->sort();   
    delete(m);
    return 0;
}