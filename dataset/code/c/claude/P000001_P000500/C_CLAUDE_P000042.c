#include <ctype.h>

const char* checkVowelOrConsonant(char c) {
    if (!isalpha(c)) return "Neither";
    char lower = tolower(c);
    if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
        return "Vowel";
    }
    return "Consonant";
}
