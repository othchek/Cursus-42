#include "Animal.hpp"

Animal::Animal() {
    std::cout << RED << "This is Animal default constructor" << RESET << std::endl;
}

Animal::Animal(std::string name) {
    this->type = name;
}

Animal::Animal(const Animal &obj) {
    (*this) = obj;
}

Animal& Animal::operator=(const Animal& obj) {
    if (this == &obj) {
        return *this;
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
