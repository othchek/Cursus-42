#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure &obj);
        Cure& operator=(const Cure& obj);
        AMateria* clone() const;
        std::string const & getType() const;
        void use(ICharacter& target);
        ~Cure();
};

#endif