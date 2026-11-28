#include <stdio.h>

int n, k;
int a[20];
int mx = 1000000000;

void gen(int i, int *sums) {
    if (i == n) {
        int mx_v = 0;
        for (int j = 0; j < k; j++) {
            if (sums[j] > mx_v) mx_v = sums[j];
        }
        if (mx_v < mx) mx = mx_v;
        return;
    }
    for (int j = 0; j < k; j++) {
        sums[j] += a[i];
        gen(i + 1, sums);
        sums[j] -= a[i];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int sums[20] = {0};
    gen(0, sums);
    printf("%d\n", mx);
    return 0;
}
