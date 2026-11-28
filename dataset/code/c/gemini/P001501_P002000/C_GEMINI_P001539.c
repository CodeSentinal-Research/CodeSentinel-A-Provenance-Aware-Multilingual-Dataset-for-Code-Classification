#include <stdbool.h>

bool isVowelChar(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowelSubstrings(char* word) {
    int ans = 0;
    for (int i = 0; word[i]; i++) {
        int mask = 0, count = 0;
        for (int j = i; word[j]; j++) {
            char c = word[j];
            if (!isVowelChar(c)) break;
            int bit = 0;
            if (c == 'a') bit = 1;
            else if (c == 'e') bit = 2;
            else if (c == 'i') bit = 4;
            else if (c == 'o') bit = 8;
            else if (c == 'u') bit = 16;

            if ((mask & bit) == 0) {
                mask |= bit;
                count++;
            }
            if (count == 5) ans++;
        }
    }
    return ans;
}