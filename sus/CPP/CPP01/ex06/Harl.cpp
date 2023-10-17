#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << ORANGE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void    Harl::info(void)
{
    std::cout << ORANGE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}


void    Harl::warning(void)
{
    std::cout << ORANGE << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void    Harl::error(void)
{
    std::cout << ORANGE << "This is unacceptable! I want to speak to the manager now." << RESET <<std::endl;
}

void Harl::complain(std::string level) {
    std::string array[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int purpose = 0;
    for (int i = 0; i < 4; i++) {
        if (array[i] == level) {
            purpose = i + 1;
            break;
        }
    }
    switch (purpose) {
        case 1:
            debug();
        case 2:
            info();
        case 3:
            warning();
        case 4:
            error();
            break;
        default:
            std::cout << RED << "[ Probably complaining about insignificant problems ]" << level << RESET << std::endl;
            break;
    }
}