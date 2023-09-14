#include <iostream>

int main(int ac, char **av) 
{
    if (ac >= 2)
    {
        for (int index = 1; av[index]; index++)
        {
            for (int i = 0; av[index][i] ; i++)
                std::cout << (char)std::toupper(av[index][i]);
        }
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
}