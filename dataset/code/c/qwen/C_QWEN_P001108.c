#include <stdio.h>
int main() {
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; }
    // Simplified reachability for small n or use BFS per query
    while(q--) {
        int u, v; scanf("%d%d", &u, &v);
        // BFS
        int visited[n], queue[n], front=0, rear=0;
        for(int i=0; i<n; i++) visited[i] = 0;
        queue[rear++] = u-1; visited[u-1] = 1;
        int found = 0;
        while(front < rear) {
            int cur = queue[front++];
            if(cur == v-1) { found = 1; break; }
            for(int i=0; i<n; i++) if(adj[cur][i] && !visited[i]) { visited[i] = 1; queue[rear++] = i; }
        }
        printf("%s\n", found ? "YES" : "NO");
    }
    return 0;
}
