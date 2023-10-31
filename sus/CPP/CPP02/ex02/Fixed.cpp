#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;

Fixed::Fixed(void) {
    stash = 0;
}

Fixed::Fixed(const int num)
{
    stash = num << fractionalbits;
}

Fixed::Fixed(const float num)
{
    stash = roundf(num * (1 << fractionalbits));
}

Fixed::Fixed(const Fixed &obj)
{  
    (*this) = (obj);
}

Fixed& Fixed::operator=(const Fixed& obj) {
    if (this != &obj)
        this->stash = obj.stash;
    return *this;
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


bool Fixed::operator==(const Fixed& obj) {
    return this->stash == obj.stash;
}

bool Fixed::operator!=(const Fixed& obj) {
    return this->stash != obj.stash;
}

bool Fixed::operator<(const Fixed& obj) {
    return this->stash < obj.stash;
}

bool Fixed::operator>(const Fixed& obj) {
    return this->stash > obj.stash;
}

bool Fixed::operator<=(const Fixed& obj) {
    return this->stash <= obj.stash;
}

bool Fixed::operator>=(const Fixed& obj) {
    return this->stash >= obj.stash;
}

Fixed Fixed::operator+(const Fixed& obj) {
    stash += obj.stash;
    return (*this);
}

Fixed Fixed::operator*(const Fixed& obj) {
    stash *= obj.toFloat();
    return (*this);
}

Fixed Fixed::operator/(const Fixed& obj) {
    stash /= obj.toFloat();
    return (*this);
}

Fixed Fixed::operator-(const Fixed& obj) {
    stash -= obj.stash;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed store;
    store = *this;
    this->stash++;
    return (store);
}

Fixed Fixed::operator--(int) {
    Fixed store;
    store = this->stash;
    this->stash--;
    return (store);
}

Fixed &Fixed::operator++() {
    this->stash++;
    return (*this);
}

Fixed &Fixed::operator--() {
    this->stash--;
    return (*this);
}

Fixed   &Fixed::min(Fixed &num, Fixed &number)
{
    if (num < number)
        return (num);
    return (number);
}
Fixed   &Fixed::max(Fixed &num, Fixed &number)
{
    if (num > number)
        return (num);
    return (number);
}

const Fixed &Fixed::min(const Fixed &num, const Fixed &number)
{
    if (num.stash < number.stash)
        return (num);
    return (number);
}

const Fixed &Fixed::max(const Fixed &num, const Fixed &number)
{
    if (num.stash > number.stash)
        return (num);
    return (number);
}

Fixed::~Fixed()
{

}