#include "ice.hpp"

Ice::Ice() {
    std::cout << PURPLE << "This is Ice default constructor" << RESET << std::endl;
    type = "ice";
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

Ice::Ice(const Ice &obj) {
    std::cout << "Ice Copy constructor called" << std::endl;
    (*this) = obj;
}

std::string const & Ice::getType() const {
    return (type);
}

Ice& Ice::operator=(const Ice& obj) {
    std::cout << PURPLE << "Ice Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}


AMateria* Ice::clone() const {
    return (new Ice);
}


Ice::~Ice() {
    std::cout << RED << "This is Ice destructor" << RESET << std::endl;
}
