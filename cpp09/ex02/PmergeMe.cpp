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


void insertUsingJacobsthal(std::vector<int> &larger, std::vector<int> &smaller) {
    int n = smaller.size();
    int past_index = 0;
    bool end = false;
    for (int i = 0; i < n; i++)
    {
        int range = jacobsthal(i);
        int c_index = past_index + range;
        if (c_index >= n)
        {
            c_index = n - 1;
            end = true;
        }
        while (c_index >= past_index)
        {
            binaryInsert(larger, smaller[c_index]);
            c_index--;
        }
        if (end)
            break;
    }
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

    // On insert les elements de smaller dans larger avec un binary search
    for (size_t i = 0; i < smaller.size(); i++)
    {
        binaryInsert(larger, smaller[i]);
    }
    //insertUsingJacobsthal(larger, smaller);
    list = larger;
}

void PmergeMe::mergeInsertSortWithVector()
{
    mergeInsertSortHelperVector(_numbersVec);
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

void PmergeMe::mergeInsertSort()
{
    if (_numbersList.empty())
        return ;
    int size = _numbersList.size();
    std::cout << "Before : ";
    displayVector(); 
    
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
    //mergeInsertSortWithList();
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    
    
    start_time = std::chrono::high_resolution_clock::now();
    mergeInsertSortWithVector();
    end_time = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);


    std::cout << "After : ";
    displayVector();
    std::cout << "Time to process a range of " << size << " elements with std::list<int> : " << duration1.count() << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector<int> : " << duration2.count() << std::endl;
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