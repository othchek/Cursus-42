#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal& operator=(const WrongAnimal& obj);
        std::string getType() const;
        void    makeSound() const;
        ~WrongAnimal();
};

#endif