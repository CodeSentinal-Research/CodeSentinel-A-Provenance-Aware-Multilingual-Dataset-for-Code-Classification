#include <string.h>
#include <stdbool.h>

bool isVowelP000287(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char* reverseVowels(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (!isVowelP000287(s[i])) i++;
        else if (!isVowelP000287(s[j])) j--;
        else {
            char temp = s[i]; s[i] = s[j]; s[j] = temp;
            i++; j--;
        }
    }
    return s;
}