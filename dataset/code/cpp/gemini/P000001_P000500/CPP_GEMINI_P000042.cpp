#include <iostream>
#include <cctype>
int main() {
    char ch;
    if (std::cin >> ch) {
        ch = std::tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') std::cout << "Vowel" << std::endl;
        else std::cout << "Consonant" << std::endl;
    }
    return 0;
}