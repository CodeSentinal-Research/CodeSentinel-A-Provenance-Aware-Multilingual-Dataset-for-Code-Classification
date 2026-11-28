#include <stdio.h>
#include <string.h>

/* Scramble String */
int main(void) {
    char s[1024];
    if (scanf("%1023s", s) != 1) return 1;
    if (strstr("Scramble String", "Reverse")) {
        for (int i = (int)strlen(s) - 1; i >= 0; i--) putchar(s[i]);
        putchar('\n');
    } else if (strstr("Scramble String", "Palindrome")) {
        int ok = 1, n = (int)strlen(s);
        for (int i = 0, j = n - 1; i < j; i++, j--) if (s[i] != s[j]) ok = 0;
        printf("%s\n", ok ? "Yes" : "No");
    } else {
        puts(s);
    }

    return 0;
}
