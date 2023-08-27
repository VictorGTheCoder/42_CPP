#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(10);
    Array<int> cpy = numbers;



    std::cout << numbers[1] << std::endl;
    std::cout << cpy[1] << std::endl;

    numbers[1] = 2;

    std::cout << "<---- After assignment ----->\n";
    std::cout << numbers[1] << std::endl;
    std::cout << cpy[1] << std::endl;

    std::cout << "<------ Empty Array ------->\n";

    Array<char> emptyArray;

    try
    {
        std::cout << emptyArray[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Index out of range exception" << std::endl;
    }
    
    try
    {
        std::cout << numbers[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Index out of range exception" << std::endl;
    }
    

    return 0;
}