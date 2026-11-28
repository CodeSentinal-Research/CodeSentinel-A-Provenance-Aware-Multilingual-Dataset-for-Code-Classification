#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Time Needed to Buy Tickets */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int k;
    if (scanf("%d", &k) != 1) k = 0;
    long long time = 0;
    for (int i = 0; i < n; i++) {
        long long take = a[k < n ? k : 0];
        if (i > k) take--;
        if (take > a[i]) take = a[i];
        if (take > 0) time += take;
    }
    printf("%lld\n", time);


    return 0;
}
