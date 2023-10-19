#include "sed.hpp"

void file_practice(std::string filename, std::string S1, std::string S2)
{
    std::string line;

    std::ifstream fileread(filename);

    std::ofstream fileout(filename.append(".replace"));

    if (!fileread.is_open() || !fileout.is_open() || S1.length() == 0 || S2.length() == 0)
    {
        std::cout << RED << "Cannot read File" << RESET << std::endl;
        return ;
    }

    while (std::getline(fileread, line))
    {
        size_t found = 0;
        while ((found = line.find(S1, found)) != std::string::npos)
        {
            line = line.substr(0, found) + S2 + line.substr(found + S1.length());
            found += S2.length();
        }
        fileout << line << std::endl;
    }
    fileread.close();
    fileout.close();
    std::cout << GREEN << "Copy Finished" << RESET << std::endl;
}
