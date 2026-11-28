#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Find Middle Node of Linked List */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    printf("%lld\n", n ? a[n / 2] : -1);


    return 0;
}
