#include <stdio.h>

int n, k;
int a[16];

int solve(int i, int *sums) {
    if (i == n) {
        for (int j = 0; j < k; j++) {
            if (sums[j] != sums[0]) return 0;
        }
        return 1;
    }
    for (int j = 0; j < k; j++) {
        sums[j] += a[i];
        if (solve(i + 1, sums)) return 1;
        sums[j] -= a[i];
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % k != 0) {
        printf("NO\n");
        return 0;
    }
    int sums[16] = {0};
    printf("%s\n", solve(0, sums) ? "YES" : "NO");
    return 0;
}
