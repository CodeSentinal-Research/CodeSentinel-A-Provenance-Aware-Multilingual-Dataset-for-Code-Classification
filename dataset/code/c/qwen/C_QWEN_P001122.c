#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int adj[n][n], radj[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = radj[i][j] = 0;
    int out_deg[n]; for(int i=0; i<n; i++) out_deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; radj[v-1][u-1] = 1; out_deg[u-1]++; }
    int safe[n]; for(int i=0; i<n; i++) safe[i] = out_deg[i] == 0;
    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i=0; i<n; i++) {
            if(safe[i]) continue;
            int all_safe = 1;
            for(int j=0; j<n; j++) if(adj[i][j] && !safe[j]) { all_safe = 0; break; }
            if(all_safe) { safe[i] = 1; changed = 1; }
        }
    }
    for(int i=0; i<n; i++) if(safe[i]) printf("%d%c", i+1, i==n-1?'\n':' ');
    printf("\n");
    return 0;
}
