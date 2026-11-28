#include <stdbool.h>

bool isVowelCh(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countCompleteVowelSubstrings(char* word) {
    int ans = 0;
    for (int i = 0; word[i]; i++) {
        int mask = 0, count = 0;
        for (int j = i; word[j]; j++) {
            char c = word[j];
            if (!isVowelCh(c)) break;
            int bit = (c == 'a' ? 1 : (c == 'e' ? 2 : (c == 'i' ? 4 : (c == 'o' ? 8 : 16))));
            if ((mask & bit) == 0) {
                mask |= bit;
                count++;
            }
            if (count == 5) ans++;
        }
    }
    return ans;
}