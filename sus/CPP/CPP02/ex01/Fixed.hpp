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
        static const int fractionalbits;
    public :
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        int getRawBits(void) const;
        float toFloat( void ) const;
        int toInt( void ) const;
};
std::ostream &operator<<(std::ostream& os, const Fixed& dt);

#endif