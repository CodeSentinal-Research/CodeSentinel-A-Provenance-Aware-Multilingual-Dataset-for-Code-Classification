#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool isVowelSmall(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char* s, int k) {
    int curVowels = 0;
    for (int i = 0; i < k; i++) if (isVowelSmall(s[i])) curVowels++;
    int maxVowels = curVowels;

    for (int i = k; s[i]; i++) {
        if (isVowelSmall(s[i])) curVowels++;
        if (isVowelSmall(s[i - k])) curVowels--;
        maxVowels = MAX(maxVowels, curVowels);
    }
    return maxVowels;
}