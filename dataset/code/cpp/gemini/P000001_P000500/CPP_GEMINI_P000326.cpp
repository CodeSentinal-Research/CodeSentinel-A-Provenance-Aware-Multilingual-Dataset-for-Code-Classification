#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string s;
    if (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        std::string word;
        int count = 0;
        while (ss >> word) count++;
        std::cout << count << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}