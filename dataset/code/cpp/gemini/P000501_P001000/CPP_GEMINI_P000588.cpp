#include <iostream>
#include <string>
int main() {
    std::string line;
    bool first = true;
    while (std::cin >> line) {
        if (!first) std::cout << " ";
        std::cout << line;
        first = false;
    }
    std::cout << std::endl;
    return 0;
}