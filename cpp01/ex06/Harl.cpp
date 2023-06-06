#include "Harl.hpp"

Harl::Harl(void) 
{
    myMap["DEBUG"] = &Harl::debug;
    myMap["INFO"] = &Harl::info;
    myMap["WARNING"] = &Harl::warning;
    myMap["ERROR"] = &Harl::error;
    myMapLevel["DEBUG"] = 0;
    myMapLevel["INFO"] = 1;
    myMapLevel["WARNING"] = 2;
    myMapLevel["ERROR"] = 3;
};

Harl::~Harl(void) {};


void Harl::complain(const std::string &level)
{
    std::map<std::string, int>::iterator it = myMapLevel.find(level);

    if (it == myMapLevel.end())
        return;
    int levelCode = it->second;
    switch (levelCode)
    {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
    default:
        std::cout << "Probably complaining about insignificant problems ]\n";
    }
    
}


void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable ! I want to speak to the manager now.\n\n";
}
