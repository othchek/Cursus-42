#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon WeaponA){
    this->name = Name;
    this->weapon = WeaponA;
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {

}