#include <stdio.h>
int parent[200001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { int a = find(i), b = find(j); parent[a] = b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); unite(u, v); }
    int count = 0;
    for(int i=1; i<=n; i++) if(parent[i] == i) count++;
    printf("%d\n", count);
    return 0;
}
