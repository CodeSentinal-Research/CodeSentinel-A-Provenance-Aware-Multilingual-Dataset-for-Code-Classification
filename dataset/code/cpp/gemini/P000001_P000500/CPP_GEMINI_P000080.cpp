#include <iostream>
#include <cctype>
int main() {
    char c;
    if (std::cin >> c) std::cout << (std::isalpha(c) ? "Alphabet" : "Not Alphabet") << std::endl;
    return 0;
}