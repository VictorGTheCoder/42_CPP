
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 90);

        Form f("Secret", 50);
        Form f2("Secret2", 50);


        std::cout << f;    
        a.signForm(f);
        a.signForm(f);

        b.signForm(f2);  
        a.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
