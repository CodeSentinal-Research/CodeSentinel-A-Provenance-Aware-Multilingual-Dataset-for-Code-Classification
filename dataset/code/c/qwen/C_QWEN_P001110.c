#include <stdio.h>
int adj[30][30], color[30], n, m_colors;
int solve(int u) {
    if(u == n) return 1;
    for(int c=1; c<=m_colors; c++) {
        int ok = 1;
        for(int v=0; v<n; v++) if(adj[u][v] && color[v] == c) { ok = 0; break; }
        if(ok) { color[u] = c; if(solve(u+1)) return 1; color[u] = 0; }
    }
    return 0;
}
int main() {
    int e; scanf("%d%d%d", &n, &e, &m_colors);
    for(int i=0; i<e; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    printf("%s\n", solve(0) ? "YES" : "NO");
    return 0;
}
