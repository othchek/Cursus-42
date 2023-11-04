#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
    std::cout << PURPLE << "MateriaSource Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* stock) {
    for(int i = 0; i < 4; i++) {
        if (i == 0 && obj[i] == NULL) {
            obj[i] = stock;
            break ;
        }
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (obj[i] && obj[i]->getType() == type)
            return (obj[i]->clone());
    }
    return (NULL);
}

MateriaSource::~MateriaSource() {
    std::cout << RED << "This is MateriaSource destructor" << RESET << std::endl;
}
