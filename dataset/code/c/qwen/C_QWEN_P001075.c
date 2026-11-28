#include <stdio.h>
int main() {
    int n, m, s; scanf("%d%d%d", &s, &n, &m); s--;
    long long dist[n]; for(int i=0; i<n; i++) dist[i] = 1000000000000000000LL;
    dist[s] = 0;
    int u[n], v[n]; long long w[n];
    for(int i=0; i<m; i++) scanf("%d%d%lld", &u[i], &v[i], &w[i]);
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            if(dist[u[j]-1] != 1000000000000000000LL && dist[u[j]-1] + w[j] < dist[v[j]-1])
                dist[v[j]-1] = dist[u[j]-1] + w[j];
        }
    }
    int neg_cycle = 0;
    for(int j=0; j<m; j++) {
        if(dist[u[j]-1] != 1000000000000000000LL && dist[u[j]-1] + w[j] < dist[v[j]-1])
            neg_cycle = 1;
    }
    if(neg_cycle) printf("NEGATIVE CYCLE\n");
    else for(int i=0; i<n; i++) printf("%lld%c", dist[i] >= 1000000000000000000LL ? -1 : dist[i], i==n-1?'\n':' ');
    return 0;
}
