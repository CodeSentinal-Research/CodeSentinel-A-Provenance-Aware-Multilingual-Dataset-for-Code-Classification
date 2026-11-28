#include <stdio.h>
int main() {
    int n, q; scanf("%d%d", &n, &q);
    int parent[n]; for(int i=0; i<n; i++) parent[i] = -1;
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<n-1; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    // BFS to set parents
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    int queue[n], front = 0, rear = 0;
    queue[rear++] = 0; visited[0] = 1;
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) if(adj[u][v] && !visited[v]) { visited[v] = 1; parent[v] = u; queue[rear++] = v; }
    }
    while(q--) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        // Simple LCA
        int anc_u[n], anc_v[n];
        int iu = 0, iv = 0;
        int cur = u;
        while(cur != -1) { anc_u[iu++] = cur; cur = parent[cur]; }
        cur = v;
        while(cur != -1) { anc_v[iv++] = cur; cur = parent[cur]; }
        int lca = 0;
        for(int i=0; i<iu && i<iv; i++) {
            if(anc_u[iu-1-i] == anc_v[iv-1-i]) lca = anc_u[iu-1-i];
            else break;
        }
        printf("%d\n", lca+1);
    }
    return 0;
}
