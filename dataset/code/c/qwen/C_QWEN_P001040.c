#include <stdio.h>
#include <stdlib.h>
struct Eng { int spd, eff; };
int cmp(const void *a, const void *b) { return ((struct Eng*)b)->eff - ((struct Eng*)a)->eff; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    struct Eng e[n];
    for(int i=0; i<n; i++) scanf("%d", &e[i].spd);
    for(int i=0; i<n; i++) scanf("%d", &e[i].eff);
    qsort(e, n, sizeof(struct Eng), cmp);
    long long sum_spd = 0, max_perf = 0;
    int spd[k]; int sz = 0;
    for(int i=0; i<n; i++) {
        sum_spd += e[i].spd;
        spd[sz++] = e[i].spd;
        if(sz > k) {
            int min_idx = 0;
            for(int j=1; j<sz; j++) if(spd[j] < spd[min_idx]) min_idx = j;
            sum_spd -= spd[min_idx];
            spd[min_idx] = spd[--sz];
        }
        long long perf = sum_spd * e[i].eff;
        if(perf > max_perf) max_perf = perf;
    }
    printf("%lld\n", max_perf);
    return 0;
}
