#include <stdio.h>
char cur[32];
void gen_no_cons_ones(int n, int idx) {
    if (idx == n) {
        cur[n] = '\0';
        printf("%s\n", cur);
        return;
    }
    cur[idx] = '0';
    gen_no_cons_ones(n, idx + 1);
    if (idx == 0 || cur[idx - 1] != '1') {
        cur[idx] = '1';
        gen_no_cons_ones(n, idx + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        gen_no_cons_ones(n, 0);
    }
    return 0;
}