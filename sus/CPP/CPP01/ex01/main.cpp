#include "Zombie.hpp"

int main() {
    int N = 20;
    std::string name = "Walker";

    Zombie *horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete[] horde;
}
