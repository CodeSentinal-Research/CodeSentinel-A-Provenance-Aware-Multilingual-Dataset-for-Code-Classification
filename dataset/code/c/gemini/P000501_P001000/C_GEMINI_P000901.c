#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isDivisibleBy11(const char* s) {
    int oddSum = 0, evenSum = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) oddSum += (s[i] - '0');
        else evenSum += (s[i] - '0');
    }
    return abs(oddSum - evenSum) % 11 == 0;
}

int main() {
    char s[2000];
    if (scanf("%1999s", s) == 1) {
        printf("%s\n", isDivisibleBy11(s) ? "YES" : "NO");
    }
    return 0;
}