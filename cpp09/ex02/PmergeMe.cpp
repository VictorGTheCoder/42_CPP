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

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **input)
{
    std::stringstream input_stringstream(*input);
    std::string arg;
    input++;
    while (*input)
    {
        arg = *input;
        if (!isNumber(arg))
        {
            std::cout << "Error" << std::endl;
            _numbersList.clear();
            _numbersVec.clear();
            return ;
        }
        int nb = std::atoi(arg.c_str());
        _numbersList.push_back(nb);
        _numbersVec.push_back(nb);
        input++;
    }
}

PmergeMe::PmergeMe(const PmergeMe &p)
{
    *this = p;
}

PmergeMe::~PmergeMe(){}


PmergeMe	&PmergeMe::operator=(const PmergeMe &pm)
{
    if (this != &pm)
    {
        this->_numbersList = pm._numbersList;
        this->_numbersVec = pm._numbersVec;
    }
	return (*this);
}

void binaryInsert(std::vector<int> &c, int val)
{
    std::vector<int>::iterator position = std::lower_bound(c.begin(), c.end(), val);
    c.insert(position, val);
}

void binaryInsertList(std::list<int> &c, int val)
{
    std::list<int>::iterator position = std::lower_bound(c.begin(), c.end(), val);
    c.insert(position, val);
}


static void mergeInsertSortHelperVector(std::vector<int> &list)
{
    if (list.size() <= 1) return;
    //Mettre les elements par paires
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < list.size(); i += 2)
        pairs.push_back(std::pair<int, int>(list[i], list[i + 1]));

    //Divisier en 2 listes des plus petits et plus grand elements de chaque liste
    std::vector<int> smaller, larger;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first > pairs[i].second)
        {
            larger.push_back(pairs[i].first);
            smaller.push_back(pairs[i].second);
        }
        else
        {
            larger.push_back(pairs[i].second);
            smaller.push_back(pairs[i].first);
        }
    }

    //Checker si il y a un elements sans paire
    if (list.size() % 2)
        smaller.push_back(list.back());
    
    //On appele recusivement avec la list des plus grand
    if (larger.size() > 1)
        mergeInsertSortHelperVector(larger);

    //On insert les elements de smaller dans larger avec un binary search
    for (size_t i = 0; i < smaller.size(); i++)
    {
        binaryInsert(larger, smaller[i]);
    }
    list = larger;
}

void PmergeMe::mergeInsertSortWithVector()
{
    int size = _numbersVec.size();
    std::chrono::microseconds timer(1000);
    long long start_time = std::chrono::high_resolution_clock::now();
    mergeInsertSortHelperVector(_numbersVec);
    std:::: end_time = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Time to process a range of " << size << " elements with std::vector<int> : " << timer.count() << std::endl;
}

static void mergeInsertSortHelperList(std::list<int> &list)
{
    if (list.size() <= 1) return;
    //Mettre les elements par paires
    std::list<std::pair<int, int> > pairs;
    //std::list<int>::iterator it = list.begin();
    while (list.size() >= 2)
    {
        int a = list.front(); list.pop_front();
        int b = list.front(); list.pop_front();
        pairs.push_back(std::pair<int, int>(a, b));
    }

    //Divisier en 2 listes des plus petits et plus grand elements de chaque liste
    std::list<int> smaller, larger;
    while (pairs.size() > 0)
    {
        int _first = pairs.front().first;
        int _second = pairs.front().second;
        pairs.pop_front();

        if (_first > _second) {
            larger.push_back(_first);
            smaller.push_back(_second);
        } else {
            larger.push_back(_second);
            smaller.push_back(_first);
        }
    }

    //Checker si il y a un elements sans paire
    if (!list.empty())
    {
        smaller.push_back(list.back());
        list.pop_back();    
    }

    //On appele recusivement avec la list des plus grand
    if (larger.size() > 1)
        mergeInsertSortHelperList(larger);

    //On insert les elements de smaller dans larger avec un binary search
    while (smaller.size() > 0)
    {
        binaryInsertList(larger, smaller.front());
        smaller.pop_front();
    }
    list = larger;
}

void PmergeMe::mergeInsertSortWithList()
{

    mergeInsertSortHelperList(_numbersList);
}

void PmergeMe::displayList()
{
    if (_numbersList.empty())
        return;
    display(_numbersList);
}

void PmergeMe::displayVector()
{
    if (_numbersVec.empty())
        return;
    display(_numbersVec);
}