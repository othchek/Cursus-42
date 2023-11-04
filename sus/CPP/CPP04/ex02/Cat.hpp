#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* ptr;
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat &obj);
        Cat& operator=(const Cat& obj);
        void    makeSound() const ;
        ~Cat();
};

#endif