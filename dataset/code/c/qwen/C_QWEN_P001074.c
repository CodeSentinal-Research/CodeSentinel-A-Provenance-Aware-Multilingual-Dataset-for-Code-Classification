#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, s; scanf("%d%d%d", &n, &m, &s); s--;
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = 1000000000000000000LL;
    dist[s] = 0;
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    int adj[n][n]; long long weight[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { adj[i][j] = 0; weight[i][j] = 1000000000000000000LL; }
    for(int i=0; i<m; i++) { int u, v; long long w; scanf("%d%d%lld", &u, &v, &w); adj[u-1][v-1] = 1; weight[u-1][v-1] = w; adj[v-1][u-1] = 1; weight[v-1][u-1] = w; }
    for(int i=0; i<n; i++) {
        int u = -1;
        for(int j=0; j<n; j++) if(!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        if(dist[u] == 1000000000000000000LL) break;
        visited[u] = 1;
        for(int v=0; v<n; v++) {
            if(adj[u][v] && dist[u] + weight[u][v] < dist[v]) dist[v] = dist[u] + weight[u][v];
        }
    }
    for(int i=0; i<n; i++) printf("%lld%c", dist[i] >= 1000000000000000000LL ? -1 : dist[i], i==n-1?'\n':' ');
    return 0;
}
