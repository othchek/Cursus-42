#include "sed.hpp"

void file_practice(std::string filename, std::string S1, std::string S2) {
    std::string line;
    std::ifstream ini_file{
        filename
    };
    std::ofstream out_file{filename.append(".replace")};
    if (ini_file && out_file) {
        while (getline(ini_file, line)) {
            size_t found = line.find(S1);
            while (found != std::string::npos) {
                line.replace(found, S1.length(), S2);
                found = line.find(S1, found + S2.length());
            }
            out_file << line << std::endl;
        }
        std::cout << "Copy Finished" << std::endl;
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}
