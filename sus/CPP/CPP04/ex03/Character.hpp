#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
class ICharacter;
class AMateria;

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class Character : public ICharacter {
    private:
        AMateria *obj[4];
        std::string name;
    public:
        Character();
        Character(std::string name);
        Character(const Character &obj);
        Character& operator=(const Character& obj);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        ~Character();
};

#endif