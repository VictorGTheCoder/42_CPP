
#include "Form.hpp"

int main()
{

    std::cout << "\n<----- Init ----->\n" << std::endl;

    Bureaucrat a("Alice", 2);
    Bureaucrat b("Bob", 90);
    Form f("Secret", false, 1);

    f.beSigned(b);
    std::cout << f;
    return 0;
}
