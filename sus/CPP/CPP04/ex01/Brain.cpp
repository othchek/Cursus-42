#include "Brain.hpp"

Brain::Brain() {
    std::cout << PURPLE << "This is Brain default constructor" << RESET << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "moraw"; 
}

Brain::Brain(std::string name) {
    std::cout << PURPLE << "This is Brain constructor" << RESET << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = name; 
}

Brain::Brain(const Brain &obj) {
    std::cout << PURPLE << "Brain Copy constructor called" << RESET << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}

Brain&  Brain::operator=(const Brain &obj) {
    std::cout << PURPLE << "Animal Copy assignment operator called" << RESET << std::endl;
    if (this == &obj) {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << RED << "Brain destructor called" << RESET << std::endl;
}