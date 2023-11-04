#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string name);
        Brain(const Brain &obj);
        Brain& operator=(const Brain& obj);
        ~Brain();
};

#endif