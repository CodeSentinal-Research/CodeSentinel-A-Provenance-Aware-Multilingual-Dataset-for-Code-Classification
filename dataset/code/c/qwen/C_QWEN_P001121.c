#include <stdio.h>
int adj[200001][2], adj_sz[200001], deg[200001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u][adj_sz[u]++] = v; adj[v][adj_sz[v]++] = u;
        deg[u]++; deg[v]++;
    }
    int q[n], front=0, rear=0;
    for(int i=0; i<n; i++) if(deg[i] <= 1) q[rear++] = i;
    int remaining = n;
    while(remaining > 2) {
        int sz = rear - front; remaining -= sz;
        for(int i=0; i<sz; i++) {
            int u = q[front++];
            for(int j=0; j<adj_sz[u]; j++) {
                int v = adj[u][j];
                if(--deg[v] == 1) q[rear++] = v;
            }
        }
    }
    for(int i=front; i<rear; i++) printf("%d%c", q[i], i==rear-1?'\n':' ');
    return 0;
}
