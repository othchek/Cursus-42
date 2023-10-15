#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string str)
{
    this->name = str;
}