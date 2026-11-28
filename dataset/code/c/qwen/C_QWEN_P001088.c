#include <stdio.h>
int main() {
    int n, m, s, k; scanf("%d%d%d%d", &n, &m, &s, &k); s--;
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = -1;
    int queue[n], front = 0, rear = 0;
    queue[rear++] = s; dist[s] = 0;
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) if(adj[u][v] && dist[v] == -1) { dist[v] = dist[u] + 1; queue[rear++] = v; }
    }
    int count = 0;
    for(int i=0; i<n; i++) if(dist[i] == k) count++;
    printf("%d\n", count);
    return 0;
}
