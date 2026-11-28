#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    qsort(vals, n, sizeof(int), cmp);
    for(int i=0; i<n; i++) printf("%d%c", vals[i], i==n-1?'\n':' ');
    return 0;
}
