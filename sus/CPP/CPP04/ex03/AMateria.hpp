#ifndef AMateria_HPP
#define AMateria_HPP

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class AMateria {
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const AMateria &obj);
        AMateria& operator=(const AMateria& obj);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        AMateria(std::string const & type);
        virtual ~AMateria();
};

#endif