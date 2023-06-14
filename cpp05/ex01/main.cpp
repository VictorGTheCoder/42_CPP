#include "Bureaucrat.hpp"

int main()
{

    std::cout << "\n<----- Init ----->\n" << std::endl;

    Bureaucrat a("Alice", 0);
    Bureaucrat b("Bob", 90);

    std::cout << "\n<----- Promote / Demote ----->\n" << std::endl;

    std::cout << b;

    b.promote(50);

    std::cout << b;

    b.demote(50);

    std::cout << b;

    b.promote(500);

    std::cout << b;

    b.demote(500);

    std::cout << b;

    return 0;
}
