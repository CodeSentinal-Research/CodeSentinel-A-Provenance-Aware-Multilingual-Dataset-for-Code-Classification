#include <iostream>
#include <string>

bool isVowel(char c) {
    char lower = tolower(c);
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

int main() {
    std::string s;
    if (std::cin >> s) {
        // Calculate midpoint to prevent potential overflow
        int mid = s.length() / 2;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < mid; i++) if (isVowel(s[i])) c1++;
        for (size_t i = mid; i < s.length(); i++) if (isVowel(s[i])) c2++;
        std::cout << (c1 == c2 ? "Yes" : "No") << std::endl;
    }
    return 0;
}