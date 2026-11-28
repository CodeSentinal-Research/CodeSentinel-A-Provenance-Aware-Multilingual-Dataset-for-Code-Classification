#include <iostream>
#include <string>
int main() {
    std::string s;
    bool first = true;
    while (std::cin >> s) {
        if (!first) std::cout << " ";
        std::cout << s;
        first = false;
    }
    std::cout << std::endl;
    return 0;
}