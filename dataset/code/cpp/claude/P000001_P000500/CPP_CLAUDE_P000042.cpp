#include <string>
#include <cctype>

class Solution {
public:
    std::string checkVowelOrConsonant(char c) {
        if (!std::isalpha(c)) return "Neither";
        char lower = std::tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            return "Vowel";
        }
        return "Consonant";
    }
};
