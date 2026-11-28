#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        int sum = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (isdigit(s[i])) {
                sum += s[i] - '0';
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}