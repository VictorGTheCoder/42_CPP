#include "PmergeMe.hpp"

bool isNumber(std::string str)
{
    for (int i = 0; i <(int) str.size(); i++)
    {
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::string input)
{
    std::stringstream input_stringstream(input);
    std::string arg;
    while (getline(input_stringstream, arg, ' '))
    {
        if (!isNumber(arg))
        {
            std::cout << "Error" << std::endl;
            return ;
        }
        int nb = std::atoi(arg.c_str());
        _list.push_front(nb);
    }
    std::cout << _list.front() << std::endl;
}

PmergeMe::~PmergeMe()
{
}

std::list<int>::iterator PmergeMe::binarySearch(std::list<int>& list, std::list<int>::iterator end, int value) {
    std::list<int>::iterator start = list.begin();
    while (start != end) {
        std::list<int>::iterator mid = start;
        std::advance(mid, std::distance(start, end) / 2);
        if (value < *mid) {
            end = mid;
        } else {
            start = mid;
            ++start;
        }
    }
    return start;
}

void PmergeMe::insertOrdered(std::list<int>& list, std::vector<int>& toInsert) {
    for (std::vector<int>::iterator it = toInsert.begin(); it != toInsert.end(); ++it) {
        int i = *it;
        std::list<int>::iterator insertPosIt = list.begin();
        std::advance(insertPosIt, i);
        std::list<int>::iterator insertPos = binarySearch(list, insertPosIt, i);
        list.insert(insertPos, i);
    }
}


void PmergeMe::sort(void)
{

    std::list<int> &list = _list;
    if (list.size() <= 1) return;

    //int n = list.size();

    // Step 1 and Step 2: Pairing and finding larger elements
    std::list<int>::iterator it = list.begin();
    std::vector<int> largerElements;
    while (it != list.end()) {
        int first = *it++;
        if (it == list.end()) {
            largerElements.push_back(first);
            break;
        }
        int second = *it++;
        if (first > second) {
            largerElements.push_back(first);
        } else {
            largerElements.push_back(second);
        }
    }

    // Step 3: Recursively sort the larger elements
    std::list<int> sortedLarger(largerElements.begin(), largerElements.end());
    sort();

    // Step 4: Insert the element that was paired with the smallest element of the sorted sequence
    std::vector<int> toInsert;
    it = list.begin();
    for (std::list<int>::iterator sortedIt = sortedLarger.begin(); sortedIt != sortedLarger.end(); ++sortedIt) {
        int el = *sortedIt;
        toInsert.push_back(*it++);
        if (*it == el) ++it;
    }
    
    list = sortedLarger;

    // Step 5: Insert the remaining elements in the special order
    insertOrdered(list, toInsert);
}