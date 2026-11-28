#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dpPal[1005][1005];

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--) {
        dpPal[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dpPal[i][j] = dpPal[i + 1][j - 1] + 2;
            } else {
                dpPal[i][j] = MAX(dpPal[i + 1][j], dpPal[i][j - 1]);
            }
        }
    }
    return dpPal[0][n - 1];
}