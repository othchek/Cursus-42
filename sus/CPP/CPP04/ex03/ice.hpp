#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class Ice : public AMateria {
    public:
        Ice();
        Ice(std::string name);
        Ice(const Ice &obj);
        Ice& operator=(const Ice& obj);
        std::string const & getType() const;
        void use(ICharacter& target);
        AMateria* clone() const;
        ~Ice();

};

#endif