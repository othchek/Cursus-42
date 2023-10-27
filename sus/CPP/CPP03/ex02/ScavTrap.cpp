#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << PURPLE << "this is ScavTrap the default constructor" << RESET << std::endl;
    this->Name = "sma3in";
    Hitpoints = 100;
    Energypoints = 50;
    Attackdamage = 20;
}

ScavTrap::ScavTrap(std::string Name) {
    std::cout << PURPLE << "ScavTrap constructor called" << RESET << std::endl;
    this->Name = Name;
    Hitpoints = 100;
    Energypoints = 50;
    Attackdamage = 20;
}

void ScavTrap::attack(const std::string& target) {
    if (Energypoints == 0 || Hitpoints == 0) {
        std::cout << ORANGE << "This ScavTrap could not "<< RESET << "attack right neow" << std::endl;
        return ;
    }
    std::cout << ORANGE << "this ScavTrap " << Name << RESET << BLUE << " attacked " << target << " for: " << Attackdamage << " of damage" << RESET << std::endl;
    Energypoints--;
}

ScavTrap::ScavTrap(const ScavTrap &obj) {
    std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
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

void    ScavTrap::guardGate() {
    std::cout << ORANGE << "ScavTrap " << Name << RESET << BLUE << " is now in Gate keeper mode" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << PURPLE << "ScavTrap Destructor called" << RESET << std::endl;
}