#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << PURPLE << "This is WrongCat default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(std::string name) {
    std::cout << PURPLE << "This is WrongCat constructor" << RESET << std::endl;
    this->type = name;
}

WrongCat::WrongCat(const WrongCat &obj) {
    std::cout << "WrongCat Copy constructor called" << std::endl;
    (*this) = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    std::cout << PURPLE << "WrongCat Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << RED << "This is WrongCat destructor" << RESET << std::endl;
}