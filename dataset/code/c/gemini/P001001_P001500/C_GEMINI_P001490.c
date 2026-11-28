#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int countBinarySubstrings(char* s) {
    int prev = 0, cur = 1, ans = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            ans += MIN(prev, cur);
            prev = cur;
            cur = 1;
        }
    }
    return ans + MIN(prev, cur);
}