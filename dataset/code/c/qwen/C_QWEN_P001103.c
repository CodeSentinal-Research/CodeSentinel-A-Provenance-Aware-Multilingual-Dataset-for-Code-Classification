#include <stdio.h>
#include <stdlib.h>
int adj[200001][2], adj_sz[200001];
int disc[200001], low[200001], timer = 0;
int bridges[200001][2], bridge_cnt = 0;
void addEdge(int u, int v) { adj[u][adj_sz[u]++] = v; adj[v][adj_sz[v]++] = u; }
void dfs(int u, int p) {
    disc[u] = low[u] = ++timer;
    for(int i=0; i<adj_sz[u]; i++) {
        int v = adj[u][i];
        if(v == p) continue;
        if(!disc[v]) {
            dfs(v, u);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if(low[v] > disc[u]) { bridges[bridge_cnt][0] = u; bridges[bridge_cnt++][1] = v; }
        } else low[u] = low[u] < disc[v] ? low[u] : disc[v];
    }
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); addEdge(u, v); }
    for(int i=0; i<n; i++) if(!disc[i]) dfs(i, -1);
    for(int i=0; i<bridge_cnt; i++) printf("%d %d\n", bridges[i][0], bridges[i][1]);
    if(bridge_cnt == 0) printf("NONE\n");
    return 0;
}
