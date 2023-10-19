#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon();
    ~Weapon();
    Weapon(std::string type);
    const std::string &getType();
    void setType(std::string Set);
};

#endif