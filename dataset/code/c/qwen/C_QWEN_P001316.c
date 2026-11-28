#include <stdio.h>

int v, e, m_colors;
int adj[20][20], col[20];

int solve(int u) {
    if (u == v) return 1;
    for (int c = 1; c <= m_colors; c++) {
        int ok = 1;
        for (int i = 0; i < v; i++) {
            if (adj[u][i] && col[i] == c) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            col[u] = c;
            if (solve(u + 1)) return 1;
            col[u] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d%d", &v, &e, &m_colors);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = 1;
    }
    printf("%s\n", solve(0) ? "YES" : "NO");
    return 0;
}
