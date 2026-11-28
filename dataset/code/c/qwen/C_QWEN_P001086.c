#include <stdio.h>
int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = -1;
    int queue[n], front = 0, rear = 0;
    for(int i=0; i<k; i++) { int s; scanf("%d", &s); dist[s-1] = 0; queue[rear++] = s-1; }
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) {
            if(adj[u][v] && dist[v] == -1) { dist[v] = dist[u] + 1; queue[rear++] = v; }
        }
    }
    for(int i=0; i<n; i++) printf("%lld%c", dist[i], i==n-1?'\n':' ');
    return 0;
}
