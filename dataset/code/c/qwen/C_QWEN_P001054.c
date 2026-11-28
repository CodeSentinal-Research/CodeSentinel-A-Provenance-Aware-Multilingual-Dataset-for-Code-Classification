#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);
    int sums[n*n], idx = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) sums[idx++] = a[i] + b[j];
    qsort(sums, idx, sizeof(int), cmp);
    for(int i=0; i<k; i++) printf("%d%c", sums[i], i==k-1?'\n':' ');
    return 0;
}
