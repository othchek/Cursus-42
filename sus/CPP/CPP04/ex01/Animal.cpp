#include "Animal.hpp"

Animal::Animal() {
    std::cout << PURPLE << "This is Animal default constructor" << RESET << std::endl;
    this->type = "default";
}

Animal::Animal(std::string name) {
    std::cout << PURPLE << "This is Animal constructor" << RESET << std::endl;
    this->type = name;
}

Animal::Animal(const Animal &obj) {
    std::cout << "Animal Copy constructor called" << std::endl;
    (*this) = obj;
}

Animal& Animal::operator=(const Animal& obj) {
    std::cout << PURPLE << "Animal Copy assignment operator called" << RESET << std::endl;
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
