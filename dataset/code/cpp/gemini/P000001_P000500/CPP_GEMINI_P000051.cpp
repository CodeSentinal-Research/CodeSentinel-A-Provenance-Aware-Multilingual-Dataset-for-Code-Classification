#include <iostream>
#include <cctype>
int main() {
    char c;
    if (std::cin >> c) std::cout << (std::isupper(c) ? "Uppercase" : "Lowercase") << std::endl;
    return 0;
}