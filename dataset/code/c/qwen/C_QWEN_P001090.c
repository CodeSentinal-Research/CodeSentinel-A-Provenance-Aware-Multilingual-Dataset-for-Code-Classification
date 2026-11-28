#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<n-1; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int bfs(int start) {
        long long dist[n]; for(int i=0; i<n; i++) dist[i] = -1;
        int queue[n], front = 0, rear = 0;
        queue[rear++] = start; dist[start] = 0;
        int farthest = start;
        while(front < rear) {
            int u = queue[front++];
            for(int v=0; v<n; v++) if(adj[u][v] && dist[v] == -1) { dist[v] = dist[u] + 1; queue[rear++] = v; if(dist[v] > dist[farthest]) farthest = v; }
        }
        return farthest;
    }
    int u = bfs(0);
    int v = bfs(u);
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = -1;
    int queue[n], front = 0, rear = 0;
    queue[rear++] = u; dist[u] = 0;
    while(front < rear) {
        int cur = queue[front++];
        for(int w=0; w<n; w++) if(adj[cur][w] && dist[w] == -1) { dist[w] = dist[cur] + 1; queue[rear++] = w; }
    }
    printf("%lld\n", dist[v]);
    return 0;
}
