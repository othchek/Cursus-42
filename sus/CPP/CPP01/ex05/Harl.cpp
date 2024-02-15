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
    void	(Harl::*ptr[5])(void);
    ptr[1] = &Harl::debug;
    ptr[2] = &Harl::info;
    ptr[3] = &Harl::warning;
    ptr[4] = &Harl::error;

    const char *converter = level.c_str();
    int purpose = std::atoi(converter);
    if (purpose >= 1 && purpose <= 4)
    {
        (this->*ptr[purpose])();
        std::cout << purpose << std::endl;
        return;
    }
    std::cout << RED << "Invalid level: " << level << RESET << std::endl;
    return;
}
