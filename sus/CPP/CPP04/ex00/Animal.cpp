#include "Animal.hpp"

Animal::Animal() {
    std::cout << RED << "This is Animal default constructor" << RESET << std::endl;
    this->type = "Animal";
}

Animal::Animal(std::string name) {
    this->type = name;
}

Animal::Animal(const Animal &obj) {
    (*this) = obj;
}

Animal& Animal::operator=(const Animal& obj) {
    if (this == &obj) {
        this->type = obj.type;
    }
    return (*this);
}

std::string Animal::getType() const {
    return (this->type);
}

void    Animal::makeSound() const {
    std::cout << PURPLE << "Seelance" << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << RED << "This is Animal destructor" << RESET << std::endl;
}
