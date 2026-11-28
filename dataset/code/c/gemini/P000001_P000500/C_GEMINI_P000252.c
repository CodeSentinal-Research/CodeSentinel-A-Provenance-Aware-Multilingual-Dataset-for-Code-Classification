#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    if (scanf("%999s", s) == 1) {
        int len = strlen(s), pal = 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) { pal = 0; break; }
        }
        printf("%s\n", pal ? "Palindrome" : "Not Palindrome");
    }
    return 0;
}