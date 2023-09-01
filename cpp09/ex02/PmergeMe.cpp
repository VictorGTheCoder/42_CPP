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

PmergeMe::PmergeMe(void)
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

PmergeMe::PmergeMe(const PmergeMe &p)
{
    *this = p;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::sort(void)
{
    std::list<int> &list = _list;




}