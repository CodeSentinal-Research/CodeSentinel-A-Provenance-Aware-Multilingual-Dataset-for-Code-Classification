#include <stdio.h>
#include <string.h>

char s[20];

void gen(int i, char *cur, int ci, int mask) {
    if (i == strlen(s)) {
        cur[ci] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int j = 0; j < 26; j++) {
        if (!(mask & (1 << j))) {
            cur[ci] = 'a' + j;
            gen(i + 1, cur, ci + 1, mask | (1 << j));
        }
    }
}

int main() {
    scanf("%s", s);
    char cur[20];
    gen(0, cur, 0, 0);
    return 0;
}
