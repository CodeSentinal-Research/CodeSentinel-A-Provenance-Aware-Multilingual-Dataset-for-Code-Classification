#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    int in_deg[n]; for(int i=0; i<n; i++) in_deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; in_deg[v-1]++; }
    int queue[n], front = 0, rear = 0;
    for(int i=0; i<n; i++) if(in_deg[i] == 0) queue[rear++] = i;
    int order[n], idx = 0;
    while(front < rear) {
        int u = queue[front++];
        order[idx++] = u+1;
        for(int v=0; v<n; v++) {
            if(adj[u][v]) { in_deg[v]--; if(in_deg[v] == 0) queue[rear++] = v; }
        }
    }
    if(idx == n) { for(int i=0; i<n; i++) printf("%d%c", order[i], i==n-1?'\n':' '); }
    else printf("IMPOSSIBLE\n");
    return 0;
}
