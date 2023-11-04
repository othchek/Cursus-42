#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *obj[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &obj);
        MateriaSource& operator=(const MateriaSource& obj);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        ~MateriaSource();
};

#endif