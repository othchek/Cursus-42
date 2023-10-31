#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << RED << "This is WrongCat default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(std::string name) {
    this->type = name;
}

WrongCat::WrongCat(const WrongCat &obj) {
    (*this) = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << RED << "This is WrongCat destructor" << RESET << std::endl;
}