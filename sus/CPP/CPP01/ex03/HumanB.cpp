#include "HumanB.hpp"

HumanB::HumanB(std::string Name){
    this->name = Name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &WeaponB) {
    weapon = &WeaponB;
}

void HumanB::attack() {
    if (weapon != NULL) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
}

HumanB::~HumanB() {

}
