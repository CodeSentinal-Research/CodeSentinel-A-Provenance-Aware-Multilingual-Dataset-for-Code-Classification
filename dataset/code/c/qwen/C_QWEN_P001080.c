#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int aps = 0;
    for(int i=0; i<n; i++) {
        // remove i
        int visited[n]; for(int j=0; j<n; j++) visited[j] = 0;
        int start = (i == 0) ? 1 : 0;
        int queue[n], front = 0, rear = 0;
        queue[rear++] = start; visited[start] = 1;
        int count = 1;
        while(front < rear) {
            int u = queue[front++];
            for(int v=0; v<n; v++) if(adj[u][v] && v != i && !visited[v]) { visited[v] = 1; queue[rear++] = v; count++; }
        }
        if(count < n-1) aps++;
    }
    if(aps == 0) printf("NONE\n");
    else printf("%d articulation points\n", aps);
    return 0;
}
