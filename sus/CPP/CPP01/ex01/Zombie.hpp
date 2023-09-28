#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie() {

    }
    Zombie(std::string name);
    void announce(void);
    ~Zombie()
    {
        std::cout << this->name << " has been destroyed!" << std::endl;
    }
};
Zombie* zombieHorde(int N, std::string name);

#endif