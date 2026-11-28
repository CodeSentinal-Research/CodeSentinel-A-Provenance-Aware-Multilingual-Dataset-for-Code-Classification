#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n], radj[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { adj[i][j] = 0; radj[i][j] = 0; }
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; radj[v-1][u-1] = 1; }
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    int order[n], idx = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            int stack[n], top = 0;
            stack[top++] = i;
            while(top > 0) {
                int u = stack[--top];
                if(!visited[u]) {
                    visited[u] = 1;
                    for(int v=0; v<n; v++) if(adj[u][v] && !visited[v]) stack[top++] = v;
                    order[idx++] = u;
                }
            }
        }
    }
    for(int i=0; i<n; i++) visited[i] = 0;
    int scc = 0;
    for(int i=n-1; i>=0; i--) {
        int u = order[i];
        if(!visited[u]) {
            int stack[n], top = 0;
            stack[top++] = u;
            while(top > 0) {
                int v = stack[--top];
                if(!visited[v]) {
                    visited[v] = 1;
                    for(int w=0; w<n; w++) if(radj[v][w] && !visited[w]) stack[top++] = w;
                }
            }
            scc++;
        }
    }
    printf("%d\n", scc);
    return 0;
}
