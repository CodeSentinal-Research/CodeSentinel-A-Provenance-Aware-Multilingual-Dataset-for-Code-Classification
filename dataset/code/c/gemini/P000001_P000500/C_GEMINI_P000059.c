#include <stdio.h>
#include <ctype.h>
int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        long long prod = 1;
        for (int i = 0; s[i] != '\0'; i++) {
            if (isdigit(s[i])) prod *= (s[i] - '0');
        }
        printf("%lld\n", prod);
    }
    return 0;
}