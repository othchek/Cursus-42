#include "PhoneBook.hpp"

int main()
{
    Contact contact;
    Phonebook search;
    std::string str;
    int i = 0;
    while (1)
    {
        std::cout << BLUE "What You See Is What You Get :" RESET << ORANGE " ADD | SEARCH | EXIT " RESET << std::endl;
        std::cout << PURPLE "Choose (: " RESET;
        if (!std::getline(std::cin, str))
            return (0);
        if (i == 8)
            i = 0;
        if (str == "ADD")
            i = store_input(&search, i);
        if (str == "SEARCH")
            Search_command(&search);
        if (str == "EXIT")
            exit (0);
    }
    return (0);
}