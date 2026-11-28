#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmpEdge(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    if (e1->w != e2->w) return e1->w - e2->w;
    int min1 = e1->u < e1->v ? e1->u : e1->v;
    int min2 = e2->u < e2->v ? e2->u : e2->v;
    if (min1 != min2) return min1 - min2;
    int max1 = e1->u > e1->v ? e1->u : e1->v;
    int max2 = e2->u > e2->v ? e2->u : e2->v;
    return max1 - max2;
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

        int count = 0;
        for (int i = 0; i < m; i++) {
            int ru = findSet(parent, edges[i].u);
            int rv = findSet(parent, edges[i].v);
            if (ru != rv) {
                parent[ru] = rv;
                int u = edges[i].u < edges[i].v ? edges[i].u : edges[i].v;
                int v = edges[i].u > edges[i].v ? edges[i].u : edges[i].v;
                printf("%d %d %d\n", u, v, edges[i].w);
                if (++count == n - 1) break;
            }
        }
        free(edges);
        free(parent);
    }
    return 0;
}