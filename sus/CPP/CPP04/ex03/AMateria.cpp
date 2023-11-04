#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default constructor" << std::endl;
    type = "Moraw";
}

AMateria::AMateria(std::string const & type) {
    std::cout << PURPLE << "This is AMateria constructor" << RESET << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria &obj) {
    std::cout << PURPLE << "AMateria Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

AMateria& AMateria::operator=(const AMateria& obj) {
    std::cout << PURPLE << "AMateria Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return (*this);
    }
    return (*this);
}

std::string const & AMateria::getType() const {
    return (type);
}

void AMateria::use(ICharacter& target) {
    std::cout << target.getName() << std::endl;
}

std::string const & AMateria::getType() const {
    return (this->type);
}

AMateria::~AMateria() {
    std::cout << RED << "This is AMateria destructor" << RESET << std::endl;
}