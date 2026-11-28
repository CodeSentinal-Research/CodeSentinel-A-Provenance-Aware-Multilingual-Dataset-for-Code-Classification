#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; }
    int color[n]; for(int i=0; i<n; i++) color[i] = 0;
    int has_cycle = 0;
    // DFS cycle detection
    int stack[n], top = -1;
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            stack[++top] = i;
            while(top >= 0) {
                int u = stack[top];
                if(color[u] == 0) { color[u] = 1; visited[u] = 1; }
                int found = 0;
                for(int v=0; v<n; v++) {
                    if(adj[u][v]) {
                        if(color[v] == 1) { has_cycle = 1; break; }
                        if(!visited[v]) { stack[++top] = v; found = 1; break; }
                    }
                }
                if(has_cycle) break;
                if(!found) { color[u] = 2; top--; }
            }
        }
        if(has_cycle) break;
    }
    printf("%s\n", has_cycle ? "YES" : "NO");
    return 0;
}
