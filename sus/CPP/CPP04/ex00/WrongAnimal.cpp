#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << RED << "This is WrongAnimal default constructor" << RESET << std::endl;
    type = "default";
}

WrongAnimal::WrongAnimal(std::string name) {
    this->type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    (*this) = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
    if (this == &obj) {
        this->type = obj.type;
    }
    return (*this);
}

std::string WrongAnimal::getType(void) const {
    return (this->type);
}

void    WrongAnimal::makeSound() const {
    std::cout << PURPLE << "Seelance" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED << "This is WrongAnimal destructor" << RESET << std::endl;
}