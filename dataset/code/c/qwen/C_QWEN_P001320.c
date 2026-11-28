#include <stdio.h>

int n;
char s[25];

void gen(int o, int c, int i) {
    if (i == 2 * n) {
        s[i] = '\0';
        printf("%s\n", s);
        return;
    }
    if (o < n) {
        s[i] = '(';
        gen(o + 1, c, i + 1);
    }
    if (c < o) {
        s[i] = ')';
        gen(o, c + 1, i + 1);
    }
}

int main() {
    scanf("%d", &n);
    gen(0, 0, 0);
    return 0;
}
