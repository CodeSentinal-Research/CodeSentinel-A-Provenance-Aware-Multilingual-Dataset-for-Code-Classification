#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    long long min_score = 0, max_score = 0;
    for(int i=0; i<k-1; i++) { min_score += a[i] + a[i+1]; max_score += a[n-1-i] + a[n-2-i]; }
    printf("%lld\n", max_score - min_score);
    return 0;
}
