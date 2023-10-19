#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon      &weapon;
public:
    HumanA(std::string Name, Weapon &WeaponA);
    void attack();
    ~HumanA();
};

#endif