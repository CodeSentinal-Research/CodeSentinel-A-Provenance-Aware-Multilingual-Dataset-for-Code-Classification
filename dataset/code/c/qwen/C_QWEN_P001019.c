#include <stdio.h>
#include <stdlib.h>
struct Point { long long x, y; };
long long dist(struct Point p) { return p.x*p.x + p.y*p.y; }
int cmp(const void *a, const void *b) { return dist(*(struct Point*)a) - dist(*(struct Point*)b); }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    struct Point pts[n];
    for(int i=0; i<n; i++) scanf("%lld%lld", &pts[i].x, &pts[i].y);
    qsort(pts, n, sizeof(struct Point), cmp);
    for(int i=0; i<k; i++) printf("%lld %lld\n", pts[i].x, pts[i].y);
    return 0;
}
