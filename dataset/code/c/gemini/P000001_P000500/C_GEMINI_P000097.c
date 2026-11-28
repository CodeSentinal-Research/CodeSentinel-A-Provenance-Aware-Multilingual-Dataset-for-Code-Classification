#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isDuckNumber(const char* s) {
    if (!s || s[0] == '0' || s[0] == '\0') return false;
    return strchr(s, '0') != NULL;
}

int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        printf("%s\n", isDuckNumber(s) ? "YES" : "NO");
    }
    return 0;
}