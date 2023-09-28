#include "sed.hpp"

int main() {
    std::string inputFilename = "original";
    std::ofstream outFile(inputFilename);
    outFile << STRING << std::endl;
    outFile.close();
    file_practice(inputFilename, ORIGINAL, REPLACE);
}
