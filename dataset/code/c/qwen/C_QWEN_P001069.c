#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m, s; scanf("%d%d%d", &n, &m, &s); s--;
    int adj[n][n], weight[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { adj[i][j] = 0; weight[i][j] = 1000000000; }
    int in_deg[n]; for(int i=0; i<n; i++) in_deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v, w; scanf("%d%d%d", &u, &v, &w); adj[u-1][v-1] = 1; weight[u-1][v-1] = w; in_deg[v-1]++; }
    int queue[n], front = 0, rear = 0;
    for(int i=0; i<n; i++) if(in_deg[i] == 0) queue[rear++] = i;
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = 1000000000000000000LL;
    dist[s] = 0;
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) {
            if(adj[u][v]) {
                if(dist[u] + weight[u][v] < dist[v]) dist[v] = dist[u] + weight[u][v];
                in_deg[v]--;
                if(in_deg[v] == 0) queue[rear++] = v;
            }
        }
    }
    for(int i=0; i<n; i++) printf("%lld%c", dist[i] >= 1000000000000000000LL ? -1 : dist[i], i==n-1?'\n':' ');
    return 0;
}
