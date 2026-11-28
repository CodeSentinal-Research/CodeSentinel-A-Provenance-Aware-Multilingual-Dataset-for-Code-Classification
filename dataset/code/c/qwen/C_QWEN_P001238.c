#include <stdio.h>
#include <stdlib.h>
struct Int { int s, e; };
int cmp(const void *a, const void *b) { return ((struct Int*)a)->s - ((struct Int*)b)->s; }
int main() {
    int n; scanf("%d", &n);
    struct Int it[n]; for(int i=0; i<n; i++) scanf("%d%d", &it[i].s, &it[i].e);
    qsort(it, n, sizeof(struct Int), cmp);
    int res[n], idx = 0;
    res[0] = it[0].s; res[1] = it[0].e; idx = 2;
    for(int i=1; i<n; i++) {
        if(it[i].s <= res[idx-1]) res[idx-1] = res[idx-1] > it[i].e ? res[idx-1] : it[i].e;
        else { res[idx++] = it[i].s; res[idx++] = it[i].e; }
    }
    for(int i=0; i<idx; i+=2) printf("[%d, %d] ", res[i], res[i+1]);
    printf("\n");
    return 0;
}
