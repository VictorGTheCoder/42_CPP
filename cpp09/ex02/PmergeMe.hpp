#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <vector>
#include <utility>


class PmergeMe
{
    private:
        std::list<int> _numbersList;
        std::vector<int> _numbersVec;
        std::list<int> _sortedlist;
        std::list<int>::iterator binarySearch(std::list<int>& list, std::list<int>::iterator end, int value);
        void insertOrdered(std::list<int>& list, std::vector<int>& toInsert);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &p);
        PmergeMe(char **input);
        ~PmergeMe();
        void mergeInsertSortWithVector();
        void mergeInsertSortWithList();

        void displayList();
        void displayVector();

        template <typename Container>
        void display(const Container& c)
        {
            typename Container::const_iterator it = c.begin();
            while (it != c.end()) {
                std::cout << *it << " ";
                ++it;
            }
            std::cout << std::endl;
        }

        PmergeMe &operator=(const PmergeMe &p);

};