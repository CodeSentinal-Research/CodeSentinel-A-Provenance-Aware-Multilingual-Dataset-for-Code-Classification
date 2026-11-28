#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int reach[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) reach[i][j] = (i==j);
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); reach[u-1][v-1] = 1; }
    for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++) reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
    for(int i=0; i<n; i++) { for(int j=0; j<n; j++) printf("%d%c", reach[i][j], j==n-1?'\n':' '); }
    return 0;
}
