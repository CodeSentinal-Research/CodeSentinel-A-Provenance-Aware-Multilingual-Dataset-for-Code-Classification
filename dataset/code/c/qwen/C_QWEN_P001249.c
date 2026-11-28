#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    long long cost = 0;
    for(int i=0; i<n-1; i++) {
        long long sum = (long long)a[i] + a[i+1];
        cost += sum;
        a[i+1] = sum;
        for(int j=i+1; j<n-1; j++) if(a[j] > a[j+1]) { int t=a[j]; a[j]=a[j+1]; a[j+1]=t; } else break;
    }
    printf("%lld\n", cost);
    return 0;
}
