#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    printf("%d\n", a[k-1]);
    return 0;
}
