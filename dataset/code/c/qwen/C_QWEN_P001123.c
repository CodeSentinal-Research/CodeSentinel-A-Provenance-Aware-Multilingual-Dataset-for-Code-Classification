#include <stdio.h>
int main() {
    int n, m, t; scanf("%d%d%d", &n, &m, &t);
    int dist[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dist[i][j] = i==j ? 0 : 1000000000;
    for(int i=0; i<m; i++) { int u, v, w; scanf("%d%d%d", &u, &v, &w); dist[u-1][v-1] = w; dist[v-1][u-1] = w; }
    for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(dist[i][k]+dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k]+dist[k][j];
    int min_reach = 1000000000, ans = -1;
    for(int i=0; i<n; i++) {
        int reach = 0;
        for(int j=0; j<n; j++) if(i!=j && dist[i][j] <= t) reach++;
        if(reach <= min_reach) { min_reach = reach; ans = i; }
    }
    printf("%d\n", ans+1);
    return 0;
}
