#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int out_deg[n]; for(int i=0; i<n; i++) out_deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); out_deg[u-1]++; }
    int count = 0;
    for(int i=0; i<n; i++) if(out_deg[i] == 0) count++;
    printf("%d\n", count);
    return 0;
}
