#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char s[10005];
    int k;
    if (scanf("%s %d", s, &k) == 2) {
        if (k == 0) {
            printf("0\n");
            return 0;
        }
        int count[256] = {0};
        int distinct = 0, l = 0, maxLen = 0;

        for (int r = 0; s[r]; r++) {
            unsigned char c = (unsigned char)s[r];
            if (count[c]++ == 0) distinct++;
            while (distinct > k) {
                unsigned char left = (unsigned char)s[l++];
                if (--count[left] == 0) distinct--;
            }
            maxLen = MAX(maxLen, r - l + 1);
        }
        printf("%d\n", maxLen);
    }
    return 0;
}