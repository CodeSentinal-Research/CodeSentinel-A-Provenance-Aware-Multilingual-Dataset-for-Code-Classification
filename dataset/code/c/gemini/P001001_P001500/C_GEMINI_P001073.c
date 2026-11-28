#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmpEdge(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        Edge* edges = (Edge*)malloc(m * sizeof(Edge));
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        qsort(edges, m, sizeof(Edge), cmpEdge);
        int* parent = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) parent[i] = i;

        long long total = 0;
        int count = 0;
        for (int i = 0; i < m; i++) {
            int ru = findSet(parent, edges[i].u);
            int rv = findSet(parent, edges[i].v);
            if (ru != rv) {
                parent[ru] = rv;
                total += edges[i].w;
                if (++count == n - 1) break;
            }
        }
        printf("%lld\n", total);
        free(edges);
        free(parent);
    }
    return 0;
}