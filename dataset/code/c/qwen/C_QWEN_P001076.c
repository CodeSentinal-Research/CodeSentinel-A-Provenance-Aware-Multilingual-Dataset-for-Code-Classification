#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    long long dist[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dist[i][j] = 1000000000000000000LL;
    for(int i=0; i<n; i++) dist[i][i] = 0;
    for(int i=0; i<m; i++) { int u, v; long long w; scanf("%d%d%lld", &u, &v, &w); dist[u-1][v-1] = w; dist[v-1][u-1] = w; }
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) printf("%lld%c", dist[i][j] >= 1000000000000000000LL ? -1 : dist[i][j], j==n-1?'\n':' ');
    }
    return 0;
}
