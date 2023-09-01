
#include "Form.hpp"

int main()
{

    std::cout << "\n<----- Init ----->\n" << std::endl;

    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 90);
        Form f("Secret", 300);

        f.beSigned(a);
        f.beSigned(a);
        std::cout << f;    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
