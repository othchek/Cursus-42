#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class ClapTrap {
    private:
        std::string Name;
        int Hitpoints;
        int Energypoints;
        int Attackdamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &obj);
        ClapTrap& operator=(const ClapTrap& obj);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};

#endif