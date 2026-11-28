#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for(int i=0; i<k; i++) a[0]++;
    long long prod = 1;
    for(int i=0; i<n; i++) prod = (prod * a[i]) % 1000000007;
    printf("%lld\n", prod);
    return 0;
}
