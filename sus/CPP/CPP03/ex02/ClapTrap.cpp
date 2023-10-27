#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << PURPLE << "this is ClapTrap default constructor" << RESET << std::endl;
    this->Name = "othman";
    Hitpoints = 10;
    Energypoints = 10;
    Attackdamage = 0;
}

ClapTrap::ClapTrap(std::string Name) 
{
    std::cout << PURPLE << "ClapTrap Constructor called" << RESET << std::endl;
    this->Name = Name;
    Hitpoints = 10;
    Energypoints = 10;
    Attackdamage = 0;
}

void ClapTrap::attack(const std::string& target) {
    if (Energypoints == 0) {
        std::cout << ORANGE << "This ClapTrap " << this->Name << RESET << BLUE <<  " could not attack right neow" << RESET << std::endl;
        return ;
    }
    std::cout << ORANGE << "this ClapTrap " << this->Name << RESET << BLUE <<  " attacked " << target << " for this amount: " << Attackdamage << " of damage" << RESET << std::endl;
    Energypoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->Energypoints > 0 && this->Hitpoints > 0)
    {
        std::cout << ORANGE << "ClapTrap " << this->Name << RESET << BLUE << " took " << amount << " points of damage!" << RESET << std::endl;
        if((int)amount > this->Hitpoints)
            this->Hitpoints = 0;
        else
            this->Hitpoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Hitpoints == 0 || Energypoints == 0) {
        std::cout << ORANGE << "This ClapTrap " << this->Name << RESET << BLUE <<  " Cant be Repaired" << RESET << std::endl;
        return ;
    }
    std::cout << ORANGE << "This ClapTrap "<< this->Name  << RESET<<  BLUE << " has been repaired for this amount: " << amount << RESET << std::endl;
    Energypoints--;
    Hitpoints += amount;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
    std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << PURPLE << "Copy assignment operator called" << RESET << std::endl;
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
    std::cout << PURPLE << "Destructor called" << RESET <<std::endl;
}