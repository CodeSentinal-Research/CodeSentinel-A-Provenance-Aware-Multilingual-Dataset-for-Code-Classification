#include <stdio.h>
int main() {
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; }
    while(q--) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%s\n", adj[u-1][v-1] ? "YES" : "NO");
    }
    return 0;
}
