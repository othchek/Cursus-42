#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[32m"

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal &obj);
        Animal& operator=(const Animal& obj);
        std::string getType() const;
        virtual void    makeSound() const;
        virtual ~Animal();
};

#endif