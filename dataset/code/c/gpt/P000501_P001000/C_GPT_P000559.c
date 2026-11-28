#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Reverse First K Elements of Queue */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int k = n;
    if (strstr("Reverse First K Elements of Queue", "First K") && scanf("%d", &k) != 1) k = n;
    if (k > n) k = n;
    for (int i = k - 1; i >= 0; i--) printf("%lld ", a[i]);
    for (int i = k; i < n; i++) printf("%lld%s", a[i], i + 1 == n ? "\n" : " ");
    if (n == 0) printf("\n");


    return 0;
}
