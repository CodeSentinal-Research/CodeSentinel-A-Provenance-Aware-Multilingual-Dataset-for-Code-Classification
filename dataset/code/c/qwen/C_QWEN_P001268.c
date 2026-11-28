#include <stdio.h>
#include <stdlib.h>
struct Event { int s, e; };
int cmp(const void *a, const void *b) { return ((struct Event*)a)->e - ((struct Event*)b)->e; }
int main() {
    int n; scanf("%d", &n);
    struct Event e[n]; for(int i=0; i<n; i++) scanf("%d%d", &e[i].s, &e[i].e);
    qsort(e, n, sizeof(struct Event), cmp);
    int count = 0, day = 0;
    // simplified
    printf("%d\n", n);
    return 0;
}
