#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
}

ClapTrap::ClapTrap(std::string Name) 
{
    std::cout << "Constructor called" << std::endl;
    this->Name = Name;
    Hitpoints = 10;
    Energypoints = 10;
    Attackdamage = 0;
}

void ClapTrap::attack(const std::string& target) {
    if (Energypoints == 0) {
        std::cout << "This ClapTrap could not attack right neow" << std::endl;
        return ;
    }
    std::cout << "this ClapTrap " << Name << " attacked " << target << " for this amount: " << Attackdamage << " of damage" << std::endl;
    Energypoints--;
    Hitpoints -= Attackdamage;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hitpoints < 1) {
        std::cout << "This ClapTrap is Deadge how unfortunate" << std::endl;
        Hitpoints = 0;
        return ;
    }
    std::cout << "This ClapTrap " << Name << " Took this ammount: " << amount << " of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Hitpoints == 0 || Energypoints == 0) {
        std::cout << "This ClapTrap Cant be Repaired" << std::endl;
        return ;
    }
    std::cout << "This ClapTrap has been repaired for this amount: " << amount << std::endl;
    Energypoints--;
    Hitpoints += amount;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
    (*this) = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    if (this == &obj) {
        return *this;
    }
    this->Name = obj.Name;
    this->Hitpoints = obj.Hitpoints;
    this->Energypoints = obj.Energypoints;
    this->Attackdamage = obj.Attackdamage;

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}