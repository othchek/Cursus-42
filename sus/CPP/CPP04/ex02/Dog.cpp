#include "Dog.hpp"

Dog::Dog() {
    std::cout << PURPLE << "This is Dog default constructor" << RESET << std::endl;
    meta = new Brain();
}

Dog::Dog(std::string name) {
    std::cout << PURPLE << "This is Dog constructor" << RESET << std::endl;
    this->type = name;
}

Dog::Dog(const Dog &obj) {
    std::cout << "Dog Copy constructor called" << std::endl;
    (*this) = obj;
}

Dog& Dog::operator=(const Dog& obj) {
    std::cout << PURPLE << "Dog Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void    Dog::makeSound() const {
    std::cout << ORANGE << this->type << RESET << BLUE << "haw haw" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "This is Dog destructor" << RESET << std::endl;
    delete meta;
}