#ifndef FIXED_HPP
#define FIXED_HPP

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

#include <iostream>

class Fixed {
    private :
        int stash;
        static const int fractionalbits = 8;
    public :
        Fixed(void);
        Fixed(const Fixed &obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif