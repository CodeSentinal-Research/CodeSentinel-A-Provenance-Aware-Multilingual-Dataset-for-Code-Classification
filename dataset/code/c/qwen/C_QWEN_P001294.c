#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    long long sum = 0, count = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        if(sum > 0) count++;
    }
    printf("%lld\n", count);
    return 0;
}
