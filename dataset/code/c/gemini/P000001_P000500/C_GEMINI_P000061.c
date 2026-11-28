#include <stdio.h>
#include <ctype.h>
int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        int count = 0;
        for (int i = 0; s[i] != '\0'; i++) if (isdigit(s[i]) && (s[i] - '0') % 2 != 0) count++;
        printf("%d\n", count);
    }
    return 0;
}