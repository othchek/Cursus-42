#include "PhoneBook.hpp"

Contact Phonebook::array_getter(int i)
{
    return (array[i]);
}

void    Phonebook::array_firstname(std::string str, int i)
{
    array[i].setter_firstname(str);
}

void    Phonebook::array_lastname(std::string str, int i)
{
    array[i].setter_lastname(str);
}

void    Phonebook::array_nickname(std::string str, int i)
{
    array[i].setter_nickname(str);
}

void    Phonebook::array_phone(std::string str, int i)
{
    array[i].setter_phone_number(str);
}

void    Phonebook::array_dark(std::string str, int i)
{
    array[i].setter_darkest_secret(str);
}

bool isAlphaString(const std::string& input) {
    for (char c : input) {
        if (!std::isalpha(c))
            return false;
    }
    return true;
}

int store_input(Phonebook *info, int i)
{
    std::string temp_firstname;
    std::string temp_lastname;
    std::string temp_nickname;
    std::string temp_phonenumber;
    std::string temp_darkestsecret;

    std::cout << "Enter First Name : ";
    if (!std::getline(std::cin, temp_firstname))
        return (i);
    if (!isAlphaString(temp_firstname)) {
        std::cout << RED "Invalid Input: First Name Cannot be a Number." RESET << std::endl;
        return (i);
    }
    std::cout << "Enter Last Name : ";
    if (!std::getline(std::cin, temp_lastname))
        return (i);
    if (!isAlphaString(temp_lastname)) {
        std::cout << RED "Invalid Input: Lastname Cannot be a Number." RESET << std::endl;
        return (i);
    }
    std::cout << "Enter Nickname : ";
    if (!std::getline(std::cin, temp_nickname))
        return (i);
    if (!isAlphaString(temp_nickname)) {
        std::cout << RED "Invalid Input: Nickname Cannot be a Number." RESET << std::endl;
        return (i);
    }
    std::cout << "Enter Phonenumber : ";
    if (!std::getline(std::cin, temp_phonenumber))
        return (i);
    if (isAlphaString(temp_phonenumber)) {
        std::cout << RED "Invalid Input: Phonenumber Cannot be a string." RESET << std::endl;
        return (i);
    }
    std::cout << "Enter Darksecret : ";
    if (!std::getline(std::cin, temp_darkestsecret))
        return (i);
    if (!isAlphaString(temp_darkestsecret)) {
        std::cout << RED "Invalid Input: Darksecret Cannot be a Number." RESET << std::endl;
        return (i);
    }
    if (!(temp_firstname.length() == 0 || temp_lastname.length() == 0 || temp_nickname.length() == 0
        || temp_phonenumber.length() == 0 || temp_darkestsecret.length() == 0))
    {
        info->array_firstname(temp_firstname, i);
        info->array_lastname(temp_lastname, i);
        info->array_nickname(temp_nickname, i);
        info->array_phone(temp_phonenumber, i);
        info->array_dark(temp_darkestsecret, i);
        std::cout << GREEN "Your Contact Has Been Added Successfully" << RESET << std::endl;
    }
    else
        std::cout << RED "Contact Cannot Be Created!" << RESET << std::endl;
    i++;
    return (i);
}

void printFormatted(const std::string &str) {
    if (str.length() <= 10) {
        std::cout << "|" << std::setw(10) << str;
    } 
    else {
        std::cout << "|" << str.substr(0, 9) + ".";
    }
}

void    Search_command(Phonebook *info)
{
    int i = 0;
    std::string str;

    std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" 
    << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    while (i < 8)
    {
        if (info->Phonebook::array_getter(i).getter_firstname().length() == 0 || info->Phonebook::array_getter(i).getter_lastname().length() == 0
            || info->Phonebook::array_getter(i).getter_nickname().length() == 0 || info->Phonebook::array_getter(i).getter_phone_number().length() == 0
                || info->Phonebook::array_getter(i).getter_darkest_secret().length() == 0)
                break ;
        std::cout << "|";
        std::cout << std::setw(10) << i;
        printFormatted(info->Phonebook::array_getter(i).getter_firstname());
        printFormatted(info->Phonebook::array_getter(i).getter_lastname());
        printFormatted(info->Phonebook::array_getter(i).getter_nickname());
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << BLUE << "what interests you the most: " << RESET;
    int index;
    if (std::cin >> index) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (index > 8) {
            std::cout << RED "Are You Blind? One digit!" << RESET <<  std::endl;
            return ;
        }
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (info->Phonebook::array_getter(index).getter_firstname().length() == 0 && info->Phonebook::array_getter(index).getter_lastname().length() == 0
	&& info->Phonebook::array_getter(index).getter_nickname().length() == 0 && info->Phonebook::array_getter(index).getter_phone_number().length() == 0 &&
	info->Phonebook::array_getter(index).getter_darkest_secret().length() == 0)
        std::cout << RED "Are You Blind? It Does Not Exist!" << RESET <<  std::endl;
    else
    {
        std::cout << "First Name : " << info->Phonebook::array_getter(index).getter_firstname() << std::endl;
		std::cout << "Last Name : " << info->Phonebook::array_getter(index).getter_lastname() << std::endl;
		std::cout << "Nick Name : " << info->Phonebook::array_getter(index).getter_nickname() << std::endl;
		std::cout << "Phone number : " << info->Phonebook::array_getter(index).getter_phone_number() << std::endl;
		std::cout << "Dark Secret : " << info->Phonebook::array_getter(index).getter_darkest_secret() << std::endl;
    }
}