#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool isVowelFull(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char s[10005];
    int k;
    if (scanf("%s %d", s, &k) == 2) {
        int l = 0, vCount = 0, maxLen = 0;

        for (int r = 0; s[r]; r++) {
            if (isVowelFull(s[r])) vCount++;
            while (vCount > k) {
                if (isVowelFull(s[l++])) vCount--;
            }
            maxLen = MAX(maxLen, r - l + 1);
        }
        printf("%d\n", maxLen);
    }
    return 0;
}