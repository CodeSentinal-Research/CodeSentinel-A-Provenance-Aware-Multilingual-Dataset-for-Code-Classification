#include <iostream>
#include <cctype>
int main() {
    char c;
    if (std::cin >> c) std::cout << (char)std::tolower(c) << std::endl;
    return 0;
}