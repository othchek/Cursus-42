#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << PURPLE << "this is FragTrap default constructor" << RESET << std::endl;
    this->Name = "abmoula";
    Hitpoints = 100;
    Energypoints = 100;
    Attackdamage = 30;
}

FragTrap::FragTrap(std::string Name) {
    std::cout << ORANGE << "FragTrap constructor called" << RESET << std::endl;
    this->Name = Name;
    Hitpoints = 100;
    Energypoints = 100;
    Attackdamage = 30;
}

void    FragTrap::highFivesGuys() {
    std::cout << ORANGE << "FragTrap " << Name << RESET << BLUE << " wants to high five you, UwU" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) {
    std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
    std::cout << PURPLE << "Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.Name;
    this->Hitpoints = obj.Hitpoints;
    this->Energypoints = obj.Energypoints;
    this->Attackdamage = obj.Attackdamage;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << PURPLE << "FragTrap Destructor called" << RESET << std::endl;
}