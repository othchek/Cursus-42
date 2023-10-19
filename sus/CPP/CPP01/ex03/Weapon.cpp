#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string Type){
    this->type = Type;
}

const std::string &Weapon::getType() {
    return (type);
}

void Weapon::setType(std::string Set) {
    type = Set;
}

Weapon::~Weapon() {
}
