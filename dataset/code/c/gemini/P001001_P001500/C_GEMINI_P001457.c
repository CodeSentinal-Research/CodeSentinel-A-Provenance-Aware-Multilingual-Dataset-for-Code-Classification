#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char s1[1005], s2[1005];
    if (scanf("%s %s", s1, s2) == 2) {
        int m = strlen(s1), n = strlen(s2);
        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                while (i + k < m && j + k < n && s1[i + k] == s2[j + k]) {
                    k++;
                }
                maxLen = MAX(maxLen, k);
            }
        }
        printf("%d\n", maxLen);
    }
    return 0;
}