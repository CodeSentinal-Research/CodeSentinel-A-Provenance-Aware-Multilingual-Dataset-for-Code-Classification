#include <stdio.h>
#include <stdlib.h>
struct P { int h, k; };
int cmp(const void *a, const void *b) {
    struct P *x = (struct P*)a, *y = (struct P*)b;
    if(x->h != y->h) return y->h - x->h;
    return x->k - y->k;
}
int main() {
    int n; scanf("%d", &n);
    struct P p[n]; for(int i=0; i<n; i++) scanf("%d%d", &p[i].h, &p[i].k);
    qsort(p, n, sizeof(struct P), cmp);
    struct P res[n]; int idx = 0;
    for(int i=0; i<n; i++) {
        int pos = p[i].k;
        for(int j=idx; j>pos; j--) res[j] = res[j-1];
        res[pos] = p[i];
        idx++;
    }
    for(int i=0; i<n; i++) printf("%d %d\n", res[i].h, res[i].k);
    return 0;
}
