#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertBase(const char* s, int b1, int b2) {
    long long val = strtoll(s, NULL, b1);
    if (val == 0) {
        printf("0\n");
        return;
    }
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[100];
    int idx = 0;
    while (val > 0) {
        buf[idx++] = digits[val % b2];
        val /= b2;
    }
    for (int i = idx - 1; i >= 0; i--) {
        putchar(buf[i]);
    }
    putchar('\n');
}

int main() {
    char s[100];
    int b1, b2;
    if (scanf("%99s %d %d", s, &b1, &b2) == 3) {
        convertBase(s, b1, b2);
    }
    return 0;
}