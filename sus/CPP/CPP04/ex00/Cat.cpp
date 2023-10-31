#include "Cat.hpp"

Cat::Cat() {
    std::cout << RED << "This is Cat default constructor" << RESET << std::endl;
}

Cat::Cat(std::string name) {
    this->type = name;
}

Cat::Cat(const Cat &obj) {
    (*this) = obj;
}

Cat& Cat::operator=(const Cat& obj) {
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void    Cat::makeSound() {
    std::cout << ORANGE << this->type << RESET << BLUE << "morew moraw" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << RED << "This is Cat destructor" << RESET << std::endl;
}