#include "Zombie.hpp"

int main() {
    Zombie *Horde;
    Horde = zombieHorde(20, "abmoula");
    for (int i = 0; i < 20; i++) {
        Horde[i].announce();
    }
    delete[] Horde;
}
