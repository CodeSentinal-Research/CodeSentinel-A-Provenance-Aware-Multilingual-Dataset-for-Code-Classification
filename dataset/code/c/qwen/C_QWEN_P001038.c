#include <stdio.h>
#include <stdlib.h>
struct Project { int cap, prof; };
int cmp_cap(const void *a, const void *b) { return ((struct Project*)a)->cap - ((struct Project*)b)->cap; }
int cmp_prof(const void *a, const void *b) { return ((struct Project*)b)->prof - ((struct Project*)a)->prof; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    struct Project p[n];
    for(int i=0; i<n; i++) scanf("%d", &p[i].cap);
    for(int i=0; i<n; i++) scanf("%d", &p[i].prof);
    int capital; scanf("%d", &capital);
    qsort(p, n, sizeof(struct Project), cmp_cap);
    long long total = capital;
    int idx = 0;
    for(int i=0; i<k; i++) {
        while(idx < n && p[idx].cap <= total) idx++;
        int max_p = -1, max_idx = -1;
        for(int j=0; j<idx; j++) {
            if(p[j].prof > max_p) { max_p = p[j].prof; max_idx = j; }
        }
        if(max_idx == -1) break;
        total += max_p;
        p[max_idx].prof = -1;
    }
    printf("%lld\n", total);
    return 0;
}
