#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        int len = strlen(s);
        int is_pal = 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) { is_pal = 0; break; }
        }
        printf("%s\n", is_pal ? "Palindrome" : "Not Palindrome");
    }
    return 0;
}