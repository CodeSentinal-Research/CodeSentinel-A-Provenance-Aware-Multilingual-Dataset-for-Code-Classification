#include <stdio.h>
#include <stdlib.h>
struct Item { int w, v; double ratio; };
int cmp(const void *a, const void *b) { return ((struct Item*)b)->ratio > ((struct Item*)a)->ratio ? 1 : -1; }
int main() {
    int n, w; scanf("%d%d", &n, &w);
    struct Item it[n];
    for(int i=0; i<n; i++) { scanf("%d%d", &it[i].w, &it[i].v); it[i].ratio = (double)it[i].v / it[i].w; }
    qsort(it, n, sizeof(struct Item), cmp);
    double total = 0;
    for(int i=0; i<n; i++) {
        if(it[i].w <= w) { total += it[i].v; w -= it[i].w; }
        else { total += it[i].ratio * w; break; }
    }
    printf("%.2f\n", total);
    return 0;
}
