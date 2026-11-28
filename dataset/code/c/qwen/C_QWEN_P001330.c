#include <stdio.h>
#include <string.h>

char s[20], cur[20];

int pal(int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return 0;
    }
    return 1;
}

void gen(int i, int j) {
    if (i == strlen(s)) {
        cur[j - 1] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int k = i; k < strlen(s); k++) {
        if (pal(i, k)) {
            int l = 0;
            for (int x = i; x <= k; x++) cur[j + l++] = s[x];
            cur[j + l] = ' ';
            gen(k + 1, j + l + 1);
        }
    }
}

int main() {
    scanf("%s", s);
    gen(0, 0);
    return 0;
}
