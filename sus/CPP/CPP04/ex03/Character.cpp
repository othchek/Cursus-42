#include "Character.hpp"

Character::Character() {
    std::cout << "Character default constructor" << std::endl;
    name = "abmoula";
    for (int i = 0; i < 4; i++) {
        obj[i] = NULL;
    }
}

Character::Character(std::string name) {
    std::cout << "Character constructor called" << std::endl;
    this->name = name;
    for (int i = 0; i < 4; i++) {
        obj[i] = NULL;
    }
}

std::string const & Character::getName() const {
    return (name);
}

void Character::equip(AMateria* m) {
    for(int i = 0; i < 4; i++) {
        if (obj[i] == NULL) {
            obj[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    obj[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && obj[idx])
        obj[idx]->use(target);
}

Character::Character(const Character &obj) {
    std::cout << "Character Copy constructor called" << std::endl;
    *this = obj;
}

Character& Character::operator=(const Character& meta) {
    std::cout << PURPLE << "Character Copy assignment operator called" << RESET << std::endl;
        for(int i = 0; i < 4; i++) {
            this->obj[i] = meta.obj[i]->clone();
        }
    return (*this);
}

Character::~Character() {
    std::cout << RED << "This is Character destructor" << RESET << std::endl;
    for(int i = 0; i < 4; i++) {
        delete obj[i];
    }
}