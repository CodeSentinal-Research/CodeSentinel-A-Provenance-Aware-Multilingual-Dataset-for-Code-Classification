#include <stdio.h>
#include <string.h>

char s[20];
int k, n;
int cur[20], idx[20];

void gen(int i, int st) {
    if (i == k) {
        for (int j = 0; j < k; j++) printf("%c", s[idx[j]]);
        printf("\n");
        return;
    }
    for (int j = st; j < n; j++) {
        idx[i] = j;
        gen(i + 1, j + 1);
    }
}

int main() {
    scanf("%s%d", s, &k);
    n = strlen(s);
    gen(0, 0);
    return 0;
}
