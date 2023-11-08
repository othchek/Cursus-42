#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        obj[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& meta) {
    std::cout << PURPLE << "MateriaSource Copy assignment operator called" << RESET << std::endl;
    for(int i = 0; i < 4; i++) {
        this->obj[i] = meta.obj[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* stock) {
    for(int i = 0; i < 4; i++) {
        if (obj[i] == NULL) {
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
    for(int i = 0; i < 4; i++) {
        delete obj[i];
    }
}
