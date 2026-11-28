#include <stdio.h>
char cur[32];
void gen_bin(int n, int idx) {
    if (idx == n) {
        cur[n] = '\0';
        printf("%s\n", cur);
        return;
    }
    cur[idx] = '0';
    gen_bin(n, idx + 1);
    cur[idx] = '1';
    gen_bin(n, idx + 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        gen_bin(n, 0);
    }
    return 0;
}