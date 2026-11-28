#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int in_deg[n+1]; for(int i=0; i<=n; i++) in_deg[i] = 0;
    int adj[n+1][n+1], adj_sz[n+1]; for(int i=0; i<=n; i++) adj_sz[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u][adj_sz[u]++] = v; in_deg[v]++; }
    int q[n+1], front=0, rear=0;
    for(int i=1; i<=n; i++) if(in_deg[i]==0) q[rear++] = i;
    int count = 0;
    while(front < rear) {
        int u = q[front++]; count++;
        for(int i=0; i<adj_sz[u]; i++) { int v = adj[u][i]; if(--in_deg[v]==0) q[rear++] = v; }
    }
    printf("%s\n", count == n ? "YES" : "NO");
    return 0;
}
