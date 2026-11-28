#include <stdio.h>

int n;
char s[25];

void gen(int i) {
    if (i == n) {
        s[i] = '\0';
        printf("%s\n", s);
        return;
    }
    s[i] = '0';
    gen(i + 1);
    if (i == 0 || s[i - 1] != '1') {
        s[i] = '1';
        gen(i + 1);
    }
}

int main() {
    scanf("%d", &n);
    gen(0);
    return 0;
}
