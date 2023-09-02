#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
        a.demote(2);
        std::cout << a << std::endl;
        a.promote(3); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
