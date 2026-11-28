#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    if(n == 0) { printf("0\n"); return 0; }
    if(n == 1) { printf("%d\n", k); return 0; }
    long long same = k, diff = (long long)k * (k - 1);
    for(int i=2; i<n; i++) {
        long long new_same = diff;
        long long new_diff = (same + diff) * (k - 1);
        same = new_same; diff = new_diff;
    }
    printf("%lld\n", same + diff);
    return 0;
}
