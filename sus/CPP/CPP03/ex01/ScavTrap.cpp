#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::string name = "abmoula";
    Name = name;
    Hitpoints = 100;
    Energypoints = 50;
    Attackdamage = 20;
}

ScavTrap::ScavTrap(std::string Name) {
    std::cout << "ScavTrap constructor called" << std::endl;
    this->Name = Name;
    Hitpoints = 100;
    Energypoints = 50;
    Attackdamage = 20;
}

void ScavTrap::attack(const std::string& target) {
    if (Energypoints == 0 || Hitpoints == 0) {
        std::cout << "This ScavTrap could not attack right neow" << std::endl;
        return ;
    }
    std::cout << "this ScavTrap " << Name << " attacked " << target << " for: " << Attackdamage << " of damage" << std::endl;
    Energypoints--;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}