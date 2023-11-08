#include "Dog.hpp"

Dog::Dog() {
    type = "dog";
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
        this->type = obj.type;
    }
    return (*this);
}

void    Dog::makeSound() const {
    std::cout << BLUE << "haw haw" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "This is Dog destructor" << RESET << std::endl;
}