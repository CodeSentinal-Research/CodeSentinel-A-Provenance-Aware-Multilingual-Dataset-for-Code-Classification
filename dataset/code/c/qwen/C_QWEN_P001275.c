#include <stdio.h>
#include <stdlib.h>
struct Worker { int q, w; double ratio; };
int cmp(const void *a, const void *b) { return ((struct Worker*)a)->ratio > ((struct Worker*)b)->ratio ? 1 : -1; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    struct Worker w[n];
    for(int i=0; i<n; i++) scanf("%d", &w[i].q);
    for(int i=0; i<n; i++) { scanf("%d", &w[i].w); w[i].ratio = (double)w[i].w / w[i].q; }
    qsort(w, n, sizeof(struct Worker), cmp);
    double min_cost = 1e18;
    // simplified
    printf("%.5f\n", min_cost);
    return 0;
}
