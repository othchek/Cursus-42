#include "Zombie.hpp"

int main() {
    int N = 20;
    std::string Name = "Walker";

    Zombie *Horde = zombieHorde(N, Name);
    for (int i = 0; i < N; i++) {
        Horde[i].announce();
    }
    delete[] Horde;
}
