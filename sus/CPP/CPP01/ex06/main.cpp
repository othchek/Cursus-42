#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl ptr;

    if (ac != 2)
        return std::cout << RED << "Invalid argument" << RESET << std::endl, 0;
    ptr.complain(av[1]);
}