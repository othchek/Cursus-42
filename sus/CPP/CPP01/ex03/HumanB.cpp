#include "HumanB.hpp"

HumanB::HumanB(std::string Name){
    this->name = Name;
}

void HumanB::setWeapon(Weapon WeaponB) {
    this->weapon = new Weapon(WeaponB);
}

void HumanB::attack() {
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
}

HumanB::~HumanB() {

}
