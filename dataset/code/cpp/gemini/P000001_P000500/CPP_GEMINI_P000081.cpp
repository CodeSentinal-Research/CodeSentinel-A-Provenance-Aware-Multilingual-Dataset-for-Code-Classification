#include <iostream>
#include <cctype>
int main() {
    char c;
    if (std::cin >> c) std::cout << (std::isdigit(c) ? "Digit" : "Not Digit") << std::endl;
    return 0;
}