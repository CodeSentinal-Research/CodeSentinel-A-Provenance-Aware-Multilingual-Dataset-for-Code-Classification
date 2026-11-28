#include <stdio.h>
int parent[100001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { parent[find(i)] = find(j); }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int type[m], u[m], v[m];
    for(int i=0; i<m; i++) scanf("%d%d%d", &type[i], &u[i], &v[i]);
    for(int i=0; i<=n; i++) parent[i] = i;
    int edges = 0;
    for(int i=0; i<m; i++) if(type[i] == 3 && find(u[i]) != find(v[i])) { unite(u[i], v[i]); edges++; }
    int p1[n+1]; for(int i=0; i<=n; i++) p1[i] = parent[i];
    for(int i=0; i<m; i++) if((type[i]==1 || type[i]==3) && find(u[i]) != find(v[i])) { unite(u[i], v[i]); edges++; }
    for(int i=0; i<=n; i++) parent[i] = p1[i];
    for(int i=0; i<m; i++) if((type[i]==2 || type[i]==3) && find(u[i]) != find(v[i])) { unite(u[i], v[i]); edges++; }
    int comp = 0;
    for(int i=1; i<=n; i++) if(find(i) == i) comp++;
    printf("%d\n", comp == 1 ? m - edges : -1);
    return 0;
}
