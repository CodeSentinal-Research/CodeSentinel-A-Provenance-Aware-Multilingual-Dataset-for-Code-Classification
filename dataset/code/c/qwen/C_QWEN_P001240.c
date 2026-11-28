#include <stdio.h>
#include <stdlib.h>
struct Int { int s, e; };
int cmp(const void *a, const void *b) { return ((struct Int*)a)->e - ((struct Int*)b)->e; }
int main() {
    int n; scanf("%d", &n);
    struct Int it[n]; for(int i=0; i<n; i++) scanf("%d%d", &it[i].s, &it[i].e);
    qsort(it, n, sizeof(struct Int), cmp);
    int count = 1, end = it[0].e;
    for(int i=1; i<n; i++) if(it[i].s < end) count++; else end = it[i].e;
    printf("%d\n", count);
    return 0;
}
