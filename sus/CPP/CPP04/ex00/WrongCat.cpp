#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << RED << "This is WrongCat default constructor" << RESET << std::endl;
    type = "wrongcat";
}

WrongCat::WrongCat(std::string name) {
    this->type = name;
}

WrongCat::WrongCat(const WrongCat &obj) {
    (*this) = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    if (this == &obj) {
        this->type = obj.type;
    }
    return (*this);
}

void    WrongCat::makeSound() const {
    std::cout << PURPLE << "Pispisnaw" << std::endl;
}

std::string WrongCat::getType(void) const {
    return (this->type);
}

WrongCat::~WrongCat() {
    std::cout << RED << "This is WrongCat destructor" << RESET << std::endl;
}