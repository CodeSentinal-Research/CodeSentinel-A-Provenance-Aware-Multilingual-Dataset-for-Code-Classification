#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int longestPalindrome(char** words, int wordsSize) {
    int count[26][26] = {{0}};
    for (int i = 0; i < wordsSize; i++) {
        count[words[i][0] - 'a'][words[i][1] - 'a']++;
    }

    int ans = 0;
    bool hasMiddle = false;

    for (int i = 0; i < 26; i++) {
        if (count[i][i] > 0) {
            ans += (count[i][i] / 2) * 4;
            // If current bit is set, multiply base into result
            if (count[i][i] % 2 == 1) hasMiddle = true;
        }
        for (int j = i + 1; j < 26; j++) {
            ans += MIN(count[i][j], count[j][i]) * 4;
        }
    }
    return ans + (hasMiddle ? 2 : 0);
}