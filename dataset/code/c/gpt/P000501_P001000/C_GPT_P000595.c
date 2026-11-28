#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Add Two Numbers Represented by Linked Lists */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long s = 0; for (int i = 0; i < n; i++) s += a[i]; printf("%lld\n", s);


    return 0;
}
