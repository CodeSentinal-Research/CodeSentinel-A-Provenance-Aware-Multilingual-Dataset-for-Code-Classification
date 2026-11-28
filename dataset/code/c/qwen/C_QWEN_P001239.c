#include <stdio.h>
#include <stdlib.h>
struct Int { int s, e; };
int cmp(const void *a, const void *b) { return ((struct Int*)a)->s - ((struct Int*)b)->s; }
int main() {
    int n; scanf("%d", &n);
    struct Int it[n]; for(int i=0; i<n; i++) scanf("%d%d", &it[i].s, &it[i].e);
    struct Int new_it; scanf("%d%d", &new_it.s, &new_it.e);
    qsort(it, n, sizeof(struct Int), cmp);
    struct Int res[n+1]; int idx = 0, i = 0;
    while(i < n && it[i].e < new_it.s) res[idx++] = it[i++];
    while(i < n && it[i].s <= new_it.e) {
        new_it.s = new_it.s < it[i].s ? new_it.s : it[i].s;
        new_it.e = new_it.e > it[i].e ? new_it.e : it[i].e;
        i++;
    }
    res[idx++] = new_it;
    while(i < n) res[idx++] = it[i++];
    for(int i=0; i<idx; i++) printf("[%d, %d] ", res[i].s, res[i].e);
    printf("\n");
    return 0;
}
