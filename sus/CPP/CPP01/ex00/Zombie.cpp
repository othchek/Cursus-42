#include "Zombie.hpp"

Zombie::Zombie(std::string str)
{
    name = str;
}

void Zombie::announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed!" << std::endl;
}
