#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; adj[v-1][u-1] = 1; }
    int v; scanf("%d", &v); v--;
    int neighbors[n], sz = 0;
    for(int i=0; i<n; i++) if(adj[v][i]) neighbors[sz++] = i+1;
    qsort(neighbors, sz, sizeof(int), cmp);
    for(int i=0; i<sz; i++) printf("%d%c", neighbors[i], i==sz-1?'\n':' ');
    return 0;
}
