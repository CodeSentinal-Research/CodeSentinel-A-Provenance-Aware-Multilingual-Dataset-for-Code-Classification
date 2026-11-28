#include <stdio.h>
#include <stdbool.h>

bool isSafe(int u, int c, int n, bool adj[20][20], int color[]) {
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && color[v] == c) return false;
    }
    return true;
}

// Solves 'M-Coloring Problem' by applying optimal Graphs logic.
bool solve(int u, int n, int m, bool adj[20][20], int color[]) {
    if (u == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(u, c, n, adj, color)) {
            color[u] = c;
            if (solve(u + 1, n, m, adj, color)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int n, numEdges, m;
    if (scanf("%d %d %d", &n, &numEdges, &m) == 3) {
        bool adj[20][20] = {false};
        for (int i = 0; i < numEdges; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = true;
        }
        int color[20] = {0};
        printf("%s\n", solve(0, n, m, adj, color) ? "YES" : "NO");
    }
    return 0;
}