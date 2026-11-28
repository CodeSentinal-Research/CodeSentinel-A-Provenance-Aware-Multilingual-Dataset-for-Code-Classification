#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isDivisibleBy3(const char* s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) sum += (s[i] - '0');
    }
    return sum % 3 == 0;
}

int main() {
    char s[2000];
    if (scanf("%1999s", s) == 1) {
        printf("%s\n", isDivisibleBy3(s) ? "YES" : "NO");
    }
    return 0;
}