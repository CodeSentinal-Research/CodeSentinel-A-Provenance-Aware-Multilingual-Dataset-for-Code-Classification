#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int maxFreq = 0, l = 0;
    int len = strlen(s);

    for (int r = 0; r < len; r++) {
        count[s[r] - 'A']++;
        maxFreq = MAX(maxFreq, count[s[r] - 'A']);

        if ((r - l + 1) - maxFreq > k) {
            count[s[l] - 'A']--;
            l++;
        }
    }
    return len - l;
}