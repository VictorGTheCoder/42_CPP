#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage : ./HarlFilter <level>\n";
        return (1);
    }

    Harl harl;

    harl.complain(argv[1]);
    /*harl.complain("ERROR");
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("WARNING");*/
    return 0;
}
