#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int total = n*n;
    int a[total];
    for(int i=0; i<total; i++) scanf("%d", &a[i]);
    qsort(a, total, sizeof(int), cmp);
    printf("%d\n", a[k-1]);
    return 0;
}
