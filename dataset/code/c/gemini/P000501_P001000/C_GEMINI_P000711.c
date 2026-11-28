#include <stdio.h>
int cur[32];
void comb(int n, int k, int start, int idx) {
    if (idx == k) {
        for (int i = 0; i < k; i++) printf("%d%s", cur[i], i == k - 1 ? "" : " ");
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++) {
        cur[idx] = i;
        comb(n, k, i + 1, idx + 1);
    }
}
int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        comb(n, k, 1, 0);
    }
    return 0;
}