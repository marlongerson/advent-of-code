#include <fstream>
#include <iostream>
#include <regex>

#define PART_2

std::string ParseInput() {
    std::ifstream inputFile("input.txt");
    return std::string(
        std::istreambuf_iterator<char>(inputFile),
        std::istreambuf_iterator<char>());
}

int main() {
    std::string input = ParseInput();
    std::string::const_iterator it = input.cbegin();
    std::smatch matches;
    int result = 0;

#if defined(PART_1)
    std::regex reg("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    while (std::regex_search(it, input.cend(), matches, reg)) {
        result += std::stoi(matches[1].str()) * std::stoi(matches[2].str());
        it = matches[0].second;
    }
#elif defined(PART_2)
    std::regex reg("don't|do|mul\\((\\d{1,3}),(\\d{1,3})\\)");
    bool enable = true;
    while (std::regex_search(it, input.cend(), matches, reg)) {
        if (matches[0].str() == "do") {
            enable = true;
        } else if (matches[0].str() == "don't") {
            enable = false;
        } else {
            if (enable) {
                result += std::stoi(matches[1].str()) * std::stoi(matches[2].str());
            }
        }
        it = matches[0].second;
    }
#endif

    std::cout << result << std::endl;
    return 0;
}