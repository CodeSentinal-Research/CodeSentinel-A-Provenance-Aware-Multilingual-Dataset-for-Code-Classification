#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) == 2) {
        int* parent = (int*)malloc(n * sizeof(int));
        parent[0] = 0;
        for (int i = 1; i < n; i++) scanf("%d", &parent[i]);

        int* depth = (int*)calloc(n, sizeof(int));
        for (int i = 1; i < n; i++) {
            int d = 0, curr = i;
            while (curr != 0) {
                curr = parent[curr];
                d++;
            }
            depth[i] = d;
        }

        while (q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            while (depth[u] > depth[v]) u = parent[u];
            while (depth[v] > depth[u]) v = parent[v];
            while (u != v) {
                u = parent[u];
                v = parent[v];
            }
            printf("%d\n", u);
        }
        free(parent);
        free(depth);
    }
    return 0;
}