#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "\n<----- Init ----->\n" << std::endl;

        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 90);

        Bureaucrat c = a;

        std::cout << c;

        std::cout << a;
        std::cout << b;

        a = b;

        std::cout << a;
        std::cout << b;

        std::cout << "\n<----- Promote / Demote ----->\n" << std::endl;

        b.promote(50);

        std::cout << b;

        b.demote(50);

        std::cout << b;

        b.promote(500);

        std::cout << b;

        b.demote(500);

        std::cout << b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
