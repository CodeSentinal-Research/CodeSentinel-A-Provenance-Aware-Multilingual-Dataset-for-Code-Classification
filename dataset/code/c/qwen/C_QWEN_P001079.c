#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int disc[n], low[n], timer = 0;
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    int bridges = 0;
    // Simplified bridge finding
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(adj[i][j]) {
                adj[i][j] = 0; adj[j][i] = 0;
                // check connectivity
                int visited2[n]; for(int k=0; k<n; k++) visited2[k] = 0;
                int queue[n], front = 0, rear = 0;
                queue[rear++] = 0; visited2[0] = 1;
                int count = 1;
                while(front < rear) {
                    int u = queue[front++];
                    for(int v=0; v<n; v++) if(adj[u][v] && !visited2[v]) { visited2[v] = 1; queue[rear++] = v; count++; }
                }
                if(count < n) bridges++;
                adj[i][j] = 1; adj[j][i] = 1;
            }
        }
    }
    if(bridges == 0) printf("NONE\n");
    else printf("%d bridges found\n", bridges);
    return 0;
}
