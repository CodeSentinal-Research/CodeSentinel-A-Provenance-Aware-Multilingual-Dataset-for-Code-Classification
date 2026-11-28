#include <stdio.h>
char cur[64];
void gen_par(int n, int o, int c, int idx) {
    if (idx == 2 * n) {
        cur[idx] = '\0';
        printf("%s\n", cur);
        return;
    }
    if (o < n) {
        cur[idx] = '(';
        gen_par(n, o + 1, c, idx + 1);
    }
    if (c < o) {
        cur[idx] = ')';
        gen_par(n, o, c + 1, idx + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        gen_par(n, 0, 0, 0);
    }
    return 0;
}