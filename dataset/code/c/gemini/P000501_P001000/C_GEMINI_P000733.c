#include <stdio.h>
#include <stdbool.h>
int adj[64][64], deg[64], colors[64];
bool is_safe(int node, int c) {
    for (int i = 0; i < deg[node]; i++) {
        int neighbor = adj[node][i];
        if (colors[neighbor] == c) return false;
    }
    return true;
}
bool backtrack(int node, int v, int m) {
    if (node == v) return true;
    for (int c = 1; c <= m; c++) {
        if (is_safe(node, c)) {
            colors[node] = c;
            if (backtrack(node + 1, v, m)) return true;
            colors[node] = 0;
        }
    }
    return false;
}
int main() {
    int v, e;
    if (scanf("%d %d", &v, &e) == 2) {
        for (int i = 0; i < e; i++) {
            int u, w; scanf("%d %d", &u, &w);
            adj[u][deg[u]++] = w;
            adj[w][deg[w]++] = u;
        }
        int m; scanf("%d", &m);
        printf("%s\n", backtrack(0, v, m) ? "true" : "false");
    }
    return 0;
}