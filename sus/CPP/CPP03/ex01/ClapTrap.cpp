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
    if (Energypoints == 0 || Hitpoints == 0) {
        std::cout << "This ClapTrap " << this->Name << " could not attack right neow" << std::endl;
        return ;
    }
    std::cout << "this ClapTrap " << this->Name << " attacked " << target << " for this amount: " << Attackdamage << " of damage" << std::endl;
    Energypoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if ((int)amount > Hitpoints) {
        std::cout << "This ClapTrap " << this->Name << " is Deadge how unfortunate" << std::endl;
        Hitpoints = 0;
        return ;
    }
    std::cout << "This ClapTrap " << this->Name << " Took this ammount: " << amount << " of damage" << std::endl;
    Hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Hitpoints == 0 || Energypoints == 0) {
        std::cout << "This ClapTrap " << this->Name << " Cant be Repaired" << std::endl;
        return ;
    }
    std::cout << "This ClapTrap "<< this->Name << " has been repaired for this amount: " << amount << std::endl;
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