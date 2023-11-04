#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* meta;
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog &obj);
        Dog& operator=(const Dog& obj);
        void    makeSound() const ;
        ~Dog();
};

#endif