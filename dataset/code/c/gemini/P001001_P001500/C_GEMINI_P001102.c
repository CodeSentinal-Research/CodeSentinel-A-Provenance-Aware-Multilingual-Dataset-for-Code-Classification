#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, cost;
} Conn;

int cmpConn(const void* a, const void* b) {
    return ((Conn*)a)->cost - ((Conn*)b)->cost;
}

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        Conn* conns = (Conn*)malloc(m * sizeof(Conn));
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &conns[i].u, &conns[i].v, &conns[i].cost);
        }
        qsort(conns, m, sizeof(Conn), cmpConn);
        int* parent = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 0; i <= n; i++) parent[i] = i;

        long long total = 0;
        int count = 0;
        for (int i = 0; i < m; i++) {
            int ru = findSet(parent, conns[i].u);
            int rv = findSet(parent, conns[i].v);
            if (ru != rv) {
                parent[ru] = rv;
                total += conns[i].cost;
                if (++count == n - 1) break;
            }
        }
        printf("%lld\n", count == n - 1 ? total : -1);
        free(conns);
        free(parent);
    }
    return 0;
}