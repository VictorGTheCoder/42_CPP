#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>

class PmergeMe
{
    private:
        std::list<int> _list;
        std::list<int> _sortedlist;
        std::list<int>::iterator binarySearch(std::list<int>& list, std::list<int>::iterator end, int value);
        void insertOrdered(std::list<int>& list, std::vector<int>& toInsert);
    public:
        PmergeMe();
        PmergeMe(std::string input);
        ~PmergeMe();
        void sort();
};
