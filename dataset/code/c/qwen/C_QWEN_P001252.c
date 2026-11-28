#include <stdio.h>
#include <stdlib.h>
struct P { int a, b; };
int cmp(const void *a, const void *b) { return ((struct P*)a)->b - ((struct P*)b)->b; }
int main() {
    int n; scanf("%d", &n);
    struct P p[n]; for(int i=0; i<n; i++) scanf("%d%d", &p[i].a, &p[i].b);
    qsort(p, n, sizeof(struct P), cmp);
    int count = 1, end = p[0].b;
    for(int i=1; i<n; i++) if(p[i].a > end) { count++; end = p[i].b; }
    printf("%d\n", count);
    return 0;
}
