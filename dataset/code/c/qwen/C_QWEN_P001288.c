#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for(int i=0; i<n && k > 0; i++) {
        if(a[i] < 0) { a[i] = -a[i]; k--; }
        else break;
    }
    if(k % 2 == 1) {
        int min_idx = 0;
        for(int i=1; i<n; i++) if(a[i] < a[min_idx]) min_idx = i;
        a[min_idx] = -a[min_idx];
    }
    long long sum = 0; for(int i=0; i<n; i++) sum += a[i];
    printf("%lld\n", sum);
    return 0;
}
