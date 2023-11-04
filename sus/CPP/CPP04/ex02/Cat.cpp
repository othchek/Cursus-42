#include "Cat.hpp"

Cat::Cat() {
    std::cout << PURPLE << "This is Cat default constructor" << RESET << std::endl;
    ptr = new Brain();
}

Cat::Cat(std::string name) {
    std::cout << PURPLE << "This is Cat constructor" << RESET << std::endl;
    this->type = name;
}

Cat::Cat(const Cat &obj) {
    std::cout << "Cat Copy constructor called" << std::endl;
    (*this) = obj;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << PURPLE << "Cat Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void    Cat::makeSound() const {
    std::cout << ORANGE << this->type << RESET << BLUE << "morew moraw" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << RED << "This is Cat destructor" << RESET << std::endl;
    delete ptr;
}