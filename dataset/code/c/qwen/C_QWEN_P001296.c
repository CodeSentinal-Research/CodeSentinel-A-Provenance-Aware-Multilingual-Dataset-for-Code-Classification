#include <stdio.h>
#include <stdlib.h>
struct Plant { int p, g; };
int cmp(const void *a, const void *b) { return ((struct Plant*)b)->g - ((struct Plant*)a)->g; }
int main() {
    int n; scanf("%d", &n);
    struct Plant pl[n];
    for(int i=0; i<n; i++) scanf("%d", &pl[i].p);
    for(int i=0; i<n; i++) scanf("%d", &pl[i].g);
    qsort(pl, n, sizeof(struct Plant), cmp);
    long long day = 0, max_day = 0;
    for(int i=0; i<n; i++) {
        day += pl[i].p;
        long long finish = day + pl[i].g;
        if(finish > max_day) max_day = finish;
    }
    printf("%lld\n", max_day);
    return 0;
}
