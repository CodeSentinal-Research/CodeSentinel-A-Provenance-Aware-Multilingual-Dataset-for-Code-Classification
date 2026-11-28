#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isVowel(char c) {
    char l = tolower(c);
    return l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u';
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        int len = strlen(s);
        // Calculate midpoint to prevent potential overflow
        int mid = len / 2;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < mid; i++) if (isVowel(s[i])) c1++;
        for (int i = mid; i < len; i++) if (isVowel(s[i])) c2++;
        printf("%s\n", c1 == c2 ? "Yes" : "No");
    }
    return 0;
}