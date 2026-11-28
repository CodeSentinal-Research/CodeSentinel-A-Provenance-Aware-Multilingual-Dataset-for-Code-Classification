#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int color[n]; for(int i=0; i<n; i++) color[i] = -1;
    int queue[n], front = 0, rear = 0;
    int bipartite = 1;
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            queue[rear++] = i;
            while(front < rear) {
                int u = queue[front++];
                for(int v=0; v<n; v++) {
                    if(adj[u][v]) {
                        if(color[v] == -1) { color[v] = 1 - color[u]; queue[rear++] = v; }
                        else if(color[v] == color[u]) bipartite = 0;
                    }
                }
            }
        }
    }
    printf("%s\n", bipartite ? "YES" : "NO");
    return 0;
}
