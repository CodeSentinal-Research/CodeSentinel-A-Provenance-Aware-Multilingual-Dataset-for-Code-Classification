#include <stdio.h>
#include <stdlib.h>
struct Bal { int s, e; };
int cmp(const void *a, const void *b) { return ((struct Bal*)a)->e - ((struct Bal*)b)->e; }
int main() {
    int n; scanf("%d", &n);
    struct Bal b[n]; for(int i=0; i<n; i++) scanf("%d%d", &b[i].s, &b[i].e);
    qsort(b, n, sizeof(struct Bal), cmp);
    int arrows = 1, end = b[0].e;
    for(int i=1; i<n; i++) if(b[i].s > end) { arrows++; end = b[i].e; }
    printf("%d\n", arrows);
    return 0;
}
