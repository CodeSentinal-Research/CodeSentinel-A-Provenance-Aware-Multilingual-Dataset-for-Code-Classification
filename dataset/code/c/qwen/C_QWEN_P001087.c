#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    int queue[n], front = 0, rear = 0;
    queue[rear++] = 0; visited[0] = 1;
    int count = 1;
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) if(adj[u][v] && !visited[v]) { visited[v] = 1; queue[rear++] = v; count++; }
    }
    if(count == n && m == n-1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
