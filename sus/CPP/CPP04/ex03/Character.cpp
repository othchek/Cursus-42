#include "Character.hpp"

Character::Character() {
    std::cout << "Character default constructor" << std::endl;
    name = "abmoula";
}

Character::Character(std::string name) {
    std::cout << "Character constructor called" << std::endl;
    this->name = name;
}

std::string const & Character::getName() const {
    return (name);
}

void Character::equip(AMateria* m) {
    for(int i = 0; i < 4; i++) {
        if (i == 0 && obj[i] == NULL) {
            obj[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    obj[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    obj[idx]->use(target);
}

Character::Character(const Character &obj) {
    std::cout << "Character Copy constructor called" << std::endl;
    *this = obj;
}

Character& Character::operator=(const Character& obj) {
    std::cout << PURPLE << "Character Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

Character::~Character() {
    std::cout << RED << "This is Character destructor" << RESET << std::endl;
}