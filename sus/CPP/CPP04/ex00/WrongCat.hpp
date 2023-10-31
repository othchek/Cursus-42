#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string name);
        WrongCat(const WrongCat &obj);
        WrongCat& operator=(const WrongCat& obj);
        void    makeSound();
        ~WrongCat();
};

#endif