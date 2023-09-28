#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string Type){
    this->type = Type;
}

std::string Weapon::getType() {
    return (type);
}

void Weapon::setType(std::string Set) {
    type = Set;
}
