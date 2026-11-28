#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool sameCharacters(const char* s1, const char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 != len2) return false;
    int count[256] = {0};
    for (int i = 0; i < len1; i++) count[(unsigned char)s1[i]]++;
    for (int i = 0; i < len2; i++) {
        if (--count[(unsigned char)s2[i]] < 0) return false;
    }
    return true;
}

int main() {
    char s1[1005], s2[1005];
    if (scanf("%1004s %1004s", s1, s2) == 2) {
        printf("%s\n", sameCharacters(s1, s2) ? "Yes" : "No");
    }
    return 0;
}