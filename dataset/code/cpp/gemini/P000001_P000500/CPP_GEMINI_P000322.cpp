#include <iostream>
#include <string>
#include <cctype>

bool detectCapitalUse(std::string word) {
    int caps = 0;
    for (char c : word) {
        if (isupper(c)) caps++;
    }
    return caps == (int)word.length() || caps == 0 || (caps == 1 && isupper(word[0]));
}

int main() {
    std::string word;
    if (std::cin >> word) {
        std::cout << (detectCapitalUse(word) ? "Yes" : "No") << std::endl;
    }
    return 0;
}