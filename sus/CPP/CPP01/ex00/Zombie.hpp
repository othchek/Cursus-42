#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string str;

public:
    Zombie(std::string str);
    void announce(void);
    ~Zombie();
};

#endif