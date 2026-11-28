#include <stdio.h>
int main() {
    int n, m, s, d, k; scanf("%d%d%d%d%d", &n, &m, &s, &d, &k);
    int dist[k+1][n];
    for(int i=0; i<=k; i++) for(int j=0; j<n; j++) dist[i][j] = 1000000000;
    dist[0][s-1] = 0;
    for(int i=0; i<m; i++) { int u, v, w; scanf("%d%d%d", &u, &v, &w); 
        for(int j=0; j<k; j++) if(dist[j][u-1] + w < dist[j+1][v-1]) dist[j+1][v-1] = dist[j][u-1] + w;
    }
    int ans = 1000000000;
    for(int i=0; i<=k; i++) if(dist[i][d-1] < ans) ans = dist[i][d-1];
    printf("%d\n", ans == 1000000000 ? -1 : ans);
    return 0;
}
