#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    void    setName(std::string str);
    Zombie() {

    }
    void announce(void);
    ~Zombie()
    {
        std::cout << this->name << " has been destroyed!" << std::endl;
    }
};
Zombie *zombieHorde(int N, std::string name);

#endif