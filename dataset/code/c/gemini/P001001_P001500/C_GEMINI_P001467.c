#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    char lower = (c >= 'A' && c <= 'Z') ? c + 32 : c;
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

char* reverseVowels(char* s) {
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        while (l < r && !isVowel(s[l])) l++;
        while (l < r && !isVowel(s[r])) r--;
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    return s;
}