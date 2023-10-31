#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    stash = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    (*this) = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    this->stash = obj.stash;
    return (*this);
}

int Fixed::getRawBits() const {
    std::cout << ORANGE << "getRawBits member function called" << RESET << std::endl; 
    return (*this).stash;
}

void Fixed::setRawBits(int const raw)
{
    (*this).stash = raw;
}

Fixed::~Fixed()
{
    std::cout << PURPLE << "Destructor called" << RESET << std::endl;
}