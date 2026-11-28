#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Shortest Unsorted Continuous Subarray */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
        long long discount = 0;
        for (int j = i + 1; j < n; j++) if (a[j] <= a[i]) { discount = a[j]; break; }
        printf("%lld%s", a[i] - discount, i + 1 == n ? "\n" : " ");
    }
    if (n == 0) printf("\n");


    return 0;
}
