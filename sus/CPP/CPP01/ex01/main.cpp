#include "Zombie.hpp"

int main()
{
    Zombie *Horde;
    Horde = zombieHorde(5, "abmoula");
    if(Horde)
    {
        for (int i = 0; i < 5; i++) {
            Horde[i].announce();
        }
        delete[] Horde;
    }
}
