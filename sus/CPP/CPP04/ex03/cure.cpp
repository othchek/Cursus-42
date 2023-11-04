#include "cure.hpp"

Cure::Cure() {
    std::cout << PURPLE << "This is Cure default constructor" << RESET << std::endl;
    type = "cure";
}

Cure::Cure(const Cure &obj) {
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = obj;
}

std::string const & Cure::getType() const {
    return (type);
}

Cure& Cure::operator=(const Cure& obj) {
    std::cout << PURPLE << "Cure Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

AMateria* Cure::clone() const {
    return (new Cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals" << target.getName() << "wounds *" << std::endl;
}

Cure::~Cure () {
    std::cout << RED << "This is Cure destructor" << RESET << std::endl;
}