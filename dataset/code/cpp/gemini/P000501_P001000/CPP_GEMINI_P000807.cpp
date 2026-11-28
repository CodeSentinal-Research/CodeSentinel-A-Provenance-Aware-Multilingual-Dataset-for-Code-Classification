#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long countEqualVowelsConsonants(const std::string& s) {
    int prefix = 0;
    long long count = 0;
    std::unordered_map<int, int> freq;
    freq[0] = 1;
    for (char c : s) {
        if (std::isalpha(c)) {
            prefix += isVowel(c) ? 1 : -1;
            if (freq.find(prefix) != freq.end()) {
                count += freq[prefix];
            }
            freq[prefix]++;
        }
    }
    return count;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << countEqualVowelsConsonants(s) << "\n";
    }
    return 0;
}