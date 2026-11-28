#include <stdio.h>
#include <stdlib.h>
struct Edge { int u, v, w; };
int cmp(const void *a, const void *b) { return ((struct Edge*)a)->w - ((struct Edge*)b)->w; }
int parent[100001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { parent[find(i)] = find(j); }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    struct Edge e[m];
    for(int i=0; i<m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    qsort(e, m, sizeof(struct Edge), cmp);
    for(int i=0; i<=n; i++) parent[i] = i;
    long long total = 0, edges = 0;
    for(int i=0; i<m; i++) {
        if(find(e[i].u) != find(e[i].v)) { unite(e[i].u, e[i].v); total += e[i].w; edges++; }
    }
    printf("%lld\n", edges == n-1 ? total : -1);
    return 0;
}
