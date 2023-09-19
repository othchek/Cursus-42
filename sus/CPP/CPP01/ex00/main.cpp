#include "Zombie.hpp"

int main()
{
    Zombie *z1;
    z1 = newZombie("Clicker");
    z1->announce();
    randomChump("Runner");
    delete z1;
}