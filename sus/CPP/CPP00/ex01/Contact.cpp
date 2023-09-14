#include "Contact.hpp"

void    Contact::setter_firstname(std::string str)
{
    this->firstname = str;
}

void    Contact::setter_lastname(std::string str)
{
    this->lastname = str;
}

void    Contact::setter_nickname(std::string str)
{
    this->nickname = str;
}

void    Contact::setter_phone_number(std::string str)
{
    this->phone_number = str;
}

void    Contact::setter_darkest_secret(std::string str)
{
    this->darkest_secret = str;
}

std::string Contact::getter_firstname(void)
{
    return (firstname);
}

std::string Contact::getter_lastname(void)
{
    return (lastname);
}

std::string Contact::getter_nickname(void)
{
    return (nickname);
}

std::string Contact::getter_phone_number(void)
{
    return (phone_number);
}

std::string Contact::getter_darkest_secret(void)
{
    return (darkest_secret);
}
