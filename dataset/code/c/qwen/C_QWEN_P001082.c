#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int deg[n]; for(int i=0; i<n; i++) deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); deg[u-1]++; deg[v-1]++; }
    int odd = 0;
    for(int i=0; i<n; i++) if(deg[i] % 2 != 0) odd++;
    if(odd == 0 || odd == 2) printf("Eulerian Path exists\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
