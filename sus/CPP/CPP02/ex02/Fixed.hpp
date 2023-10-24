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

        bool operator==(const Fixed& obj);
        bool operator!=(const Fixed& obj);
        bool operator<(const Fixed& obj);
        bool operator>(const Fixed& obj);
        bool operator<=(const Fixed& obj);
        bool operator>=(const Fixed& obj);

        Fixed& operator=(const Fixed& b);
	    Fixed operator+(const Fixed& b);
	    Fixed operator*(const Fixed& b);
	    Fixed operator/(const Fixed& b);
	    Fixed operator-(const Fixed& b);

        Fixed operator++(int);
	    Fixed operator--(int);
	    Fixed &operator++();
	    Fixed &operator--();

        int getRawBits(void) const;
        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed &min(Fixed &num, Fixed &number);
        static Fixed &max(Fixed &num, Fixed &number);

        static const Fixed &min(const Fixed &num, const Fixed &number);
        static const Fixed &max(const Fixed &num, const Fixed &number);
        ~Fixed();
};
std::ostream &operator<<(std::ostream& os, const Fixed& dt);

#endif