#include <stdio.h>
#include <stdlib.h>
struct Person { int a, b; int diff; };
int cmp(const void *a, const void *b) { return ((struct Person*)a)->diff - ((struct Person*)b)->diff; }
int main() {
    int n; scanf("%d", &n);
    struct Person p[2*n];
    for(int i=0; i<2*n; i++) { scanf("%d%d", &p[i].a, &p[i].b); p[i].diff = p[i].a - p[i].b; }
    qsort(p, 2*n, sizeof(struct Person), cmp);
    int cost = 0;
    for(int i=0; i<n; i++) cost += p[i].a;
    for(int i=n; i<2*n; i++) cost += p[i].b;
    printf("%d\n", cost);
    return 0;
}
