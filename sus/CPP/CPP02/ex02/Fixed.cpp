#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;

Fixed::Fixed(void) {
    
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    stash = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << GREEN << "Int constructor called" << RESET << std::endl;
    stash = num << fractionalbits;
}

Fixed::Fixed(const float num)
{
    std::cout << GREEN << "Float constructor called" << RESET << std::endl;
    stash = roundf(num * (1 << fractionalbits));
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

Fixed Fixed::operator=(const Fixed& obj)
{
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    this->stash = obj.stash;
    return (*this);
}

int Fixed::getRawBits() const 
{
    return stash;
}

std::ostream &operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

float Fixed::toFloat( void ) const
{
    return ((float)stash / (1 << fractionalbits));
}

int Fixed::toInt( void ) const {
    return (this->stash >> fractionalbits);
}

bool Fixed::operator==(const Fixed& obj) const {

}

bool Fixed::operator!=(const Fixed& obj) const {

}

bool Fixed::operator<(const Fixed& obj) const {

}

bool Fixed::operator>(const Fixed& obj) const {

}

bool Fixed::operator<=(const Fixed& obj) const {

}

bool Fixed::operator>=(const Fixed& obj) const {

}

Fixed Fixed::operator+(const Fixed& obj) {

}

Fixed Fixed::operator*(const Fixed& obj) {

}

Fixed Fixed::operator/(const Fixed& obj) {

}

Fixed Fixed::operator-(const Fixed& obj) {

}

Fixed::~Fixed()
{
    std::cout << PURPLE << "Destructor called" << RESET << std::endl;
}