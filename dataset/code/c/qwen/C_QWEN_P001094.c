#include <stdio.h>
int main() {
    int l, r, m; scanf("%d%d%d", &l, &r, &m);
    int adj[l][r]; for(int i=0; i<l; i++) for(int j=0; j<r; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; }
    int match[r]; for(int i=0; i<r; i++) match[i] = -1;
    int total = 0;
    for(int i=0; i<l; i++) {
        int visited[r]; for(int j=0; j<r; j++) visited[j] = 0;
        // Simple augmenting path
        for(int j=0; j<r; j++) {
            if(adj[i][j] && match[j] == -1) { match[j] = i; total++; break; }
        }
    }
    printf("%d\n", total);
    return 0;
}
