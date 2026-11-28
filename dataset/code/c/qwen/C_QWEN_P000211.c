#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    long long arr[n];
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    qsort(arr, n, sizeof(long long), cmp);
    long long p1 = arr[n-1]*arr[n-2]*arr[n-3];
    long long p2 = arr[0]*arr[1]*arr[n-1];
    printf("%lld\n", p1 > p2 ? p1 : p2);
    return 0;
}
