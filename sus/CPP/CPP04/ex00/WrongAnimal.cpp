#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << RED << "This is WrongAnimal default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) {
    this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    (*this) = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
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