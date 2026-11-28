#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<n-1; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    // Find center by removing leaves
    int deg[n]; for(int i=0; i<n; i++) deg[i] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(adj[i][j]) deg[i]++;
    int queue[n], front = 0, rear = 0;
    for(int i=0; i<n; i++) if(deg[i] == 1) queue[rear++] = i;
    int remaining = n;
    while(remaining > 2) {
        int sz = rear - front;
        remaining -= sz;
        for(int i=0; i<sz; i++) {
            int u = queue[front++];
            for(int v=0; v<n; v++) if(adj[u][v]) { deg[v]--; if(deg[v] == 1) queue[rear++] = v; }
        }
    }
    for(int i=front; i<rear; i++) printf("%d%c", queue[i]+1, i==rear-1?'\n':' ');
    return 0;
}
