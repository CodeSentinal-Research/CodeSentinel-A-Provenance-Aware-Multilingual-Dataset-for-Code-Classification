#include <stdio.h>
#include <stdbool.h>

bool isSafe(int node, int c, int v, int adj[][105], int color[]) {
    for (int i = 0; i < v; i++) {
        if (adj[node][i] == 1 && color[i] == c) return false;
    }
    return true;
}

// Solves 'M-Coloring Problem' by applying optimal Backtracking logic.
bool solve(int node, int m, int v, int adj[][105], int color[]) {
    if (node == v) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, v, adj, color)) {
            color[node] = c;
            if (solve(node + 1, m, v, adj, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    int v, m, e;
    if (scanf("%d %d %d", &v, &m, &e) == 3) {
        int adj[105][105] = {0};
        for (int i = 0; i < e; i++) {
            int u, w;
            scanf("%d %d", &u, &w);
            adj[u][w] = 1;
            adj[w][u] = 1;
        }
        int color[105] = {0};
        printf("%d\n", solve(0, m, v, adj, color) ? 1 : 0);
    }
    return 0;
}