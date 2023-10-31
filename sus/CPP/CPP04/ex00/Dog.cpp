#include "Dog.hpp"

Dog::Dog() {
    std::cout << RED << "This is Dog default constructor" << RESET << std::endl;
}

Dog::Dog(std::string name) {
    this->type = name;
}

Dog::Dog(const Dog &obj) {
    (*this) = obj;
}

Dog& Dog::operator=(const Dog& obj) {
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void    Dog::makeSound() {
    std::cout << ORANGE << this->type << RESET << BLUE << "haw haw" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "This is Dog destructor" << RESET << std::endl;
}