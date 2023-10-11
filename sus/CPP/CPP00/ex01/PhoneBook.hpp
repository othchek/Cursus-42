#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class Phonebook {
    private:
        Contact array[8];
    public:
        Contact array_getter(int i);
        void    array_firstname(std::string str, int i);
        void    array_lastname(std::string str, int i);
        void    array_nickname(std::string str, int i);
        void    array_phone(std::string str, int i);
        void    array_dark(std::string str, int i);
};
int store_input(Phonebook *info, int i);
void    Search_command(Phonebook *info);
#endif