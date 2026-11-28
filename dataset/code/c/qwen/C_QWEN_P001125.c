#include <stdio.h>
#include <stdlib.h>
struct Edge { int to, w; };
int main() {
    int n, m, s; scanf("%d%d%d", &n, &m, &s);
    int dist[n+1]; for(int i=0; i<=n; i++) dist[i] = 1000000000;
    dist[s] = 0;
    int u[m], v[m], w[m];
    for(int i=0; i<m; i++) scanf("%d%d%d", &u[i], &v[i], &w[i]);
    for(int i=0; i<n-1; i++) for(int j=0; j<m; j++) if(dist[u[j]] + w[j] < dist[v[j]]) dist[v[j]] = dist[u[j]] + w[j];
    int max_d = 0;
    for(int i=1; i<=n; i++) if(dist[i] > max_d) max_d = dist[i];
    printf("%d\n", max_d == 1000000000 ? -1 : max_d);
    return 0;
}
