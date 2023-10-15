#include "sed.hpp"

int main(int ac, char **av) {
    if (ac == 4)
    {
        std::ifstream outFile(av[1]);
        if (!outFile.is_open())
            return std::cout << RED << "File does not exist" << RESET << std::endl, 0;
        file_practice(av[1], av[2], av[3]);
    }
    else
        std::cout << RED << "Invalid Arguments" << RESET << std::endl;
}
