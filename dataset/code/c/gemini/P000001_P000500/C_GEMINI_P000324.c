#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(const char* s) {
    int n = strlen(s);
    char ss[2005];
    strcpy(ss, s);
    strcat(ss, s);
    ss[2 * n - 1] = '\0';
    return strstr(ss + 1, s) != NULL;
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        printf("%s\n", repeatedSubstringPattern(s) ? "Yes" : "No");
    }
    return 0;
}