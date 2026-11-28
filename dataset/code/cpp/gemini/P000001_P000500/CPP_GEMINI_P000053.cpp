#include <iostream>
#include <cctype>
int main() {
    char c;
    if (std::cin >> c) std::cout << (char)std::toupper(c) << std::endl;
    return 0;
}