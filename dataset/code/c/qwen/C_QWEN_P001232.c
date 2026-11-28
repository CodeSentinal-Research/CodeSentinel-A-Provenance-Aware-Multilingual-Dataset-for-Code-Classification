#include <stdio.h>
#include <stdlib.h>
struct Act { int s, f; };
int cmp(const void *a, const void *b) { return ((struct Act*)a)->f - ((struct Act*)b)->f; }
int main() {
    int n; scanf("%d", &n);
    struct Act a[n]; for(int i=0; i<n; i++) scanf("%d%d", &a[i].s, &a[i].f);
    qsort(a, n, sizeof(struct Act), cmp);
    int count = 1, end = a[0].f;
    for(int i=1; i<n; i++) if(a[i].s >= end) { count++; end = a[i].f; }
    printf("%d\n", count);
    return 0;
}
