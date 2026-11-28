#include <iostream>
#include <string>

bool validWordAbbreviation(std::string word, std::string abbr) {
    size_t i = 0, j = 0;
    while (i < word.length() && j < abbr.length()) {
        if (isdigit(abbr[j])) {
            if (abbr[j] == '0') return false;
            int num = 0;
            while (j < abbr.length() && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j++] - '0');
            }
            i += num;
        } else {
            if (word[i] != abbr[j]) return false;
            i++;
            j++;
        }
    }
    return i == word.length() && j == abbr.length();
}

int main() {
    std::string word, abbr;
    if (std::cin >> word >> abbr) {
        std::cout << (validWordAbbreviation(word, abbr) ? "Yes" : "No") << std::endl;
    }
    return 0;
}