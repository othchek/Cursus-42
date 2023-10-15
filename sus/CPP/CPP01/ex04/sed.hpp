#ifndef SED_HPP
#define SED_HPP

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

#include <iostream>
#include <fstream>

void file_practice(std::string filename, std::string S1, std::string S2);

#endif