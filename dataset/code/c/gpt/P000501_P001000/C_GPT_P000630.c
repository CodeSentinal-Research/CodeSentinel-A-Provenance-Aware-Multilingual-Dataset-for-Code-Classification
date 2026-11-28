#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Find the Kth Node from the End */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long key;
    if (scanf("%lld", &key) != 1) key = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) if (a[i] == key) { pos = i; break; }
    printf("%d\n", pos);


    return 0;
}
