#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << PURPLE << "This is WrongAnimal default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) {
    std::cout << PURPLE << "This is WrongAnimal constructor" << RESET << std::endl;
    this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    (*this) = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
    std::cout << PURPLE << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void    WrongAnimal::makeSound() {
    std::cout << PURPLE << "Seelance" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED << "This is WrongAnimal destructor" << RESET << std::endl;
}