#include <stdio.h>
#include <stdlib.h>
struct Box { int num, units; };
int cmp(const void *a, const void *b) { return ((struct Box*)b)->units - ((struct Box*)a)->units; }
int main() {
    int n, t; scanf("%d%d", &n, &t);
    struct Box b[n]; for(int i=0; i<n; i++) scanf("%d%d", &b[i].num, &b[i].units);
    qsort(b, n, sizeof(struct Box), cmp);
    int total = 0;
    for(int i=0; i<n; i++) {
        int take = b[i].num < t ? b[i].num : t;
        total += take * b[i].units;
        t -= take;
        if(t == 0) break;
    }
    printf("%d\n", total);
    return 0;
}
