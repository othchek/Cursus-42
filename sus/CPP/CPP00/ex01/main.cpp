#include "PhoneBook.hpp"

int main()
{
    Contact contact;
    Phonebook search;
    std::string str;
    int i = 0;
    while (1)
    {
        std::cout << BLUE "What You See Is What You Get :" RESET << ORANGE " Add | Search | Exit " RESET << std::endl;
        std::cout << PURPLE "Choose (: " RESET;
        if (!std::getline(std::cin, str))
            return (0);
        if (str == "Add")
            i = store_input(&search, i);
        if (str == "Search")
            Search_command(&search);
        if (str == "Exit")
            exit (0);
    }
    return (0);
}