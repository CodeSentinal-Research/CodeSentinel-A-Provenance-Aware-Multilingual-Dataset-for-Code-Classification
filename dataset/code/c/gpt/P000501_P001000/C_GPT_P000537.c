#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Sliding Window Maximum */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int k;
    if (scanf("%d", &k) != 1 || k <= 0) k = 1;
    for (int i = 0; i + k <= n; i++) {
        long long mx = a[i];
        for (int j = i + 1; j < i + k; j++) if (a[j] > mx) mx = a[j];
        printf("%lld%s", mx, i + k == n ? "\n" : " ");
    }


    return 0;
}
