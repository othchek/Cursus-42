#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    this->Name = "abmoula";
    Hitpoints = 10;
    Energypoints = 10;
    Attackdamage = 0;
}

ClapTrap::ClapTrap(std::string Name) 
{
    std::cout << "ClapTrap Constructor called" << std::endl;
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
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->Energypoints > 0 && this->Hitpoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " took " << amount << " points of damage!" << std::endl;
        if((int)amount > this->Hitpoints)
            this->Hitpoints = 0;
        else
            this->Hitpoints -= amount;
    }
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
    std::cout << "Copy constructor called" << std::endl;
    (*this) = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
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