#include <stdio.h>
int parent[200001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { int a = find(i), b = find(j); parent[a] = b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++) parent[i] = i;
    int cycle = 0;
    for(int i=0; i<m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if(find(u) == find(v)) cycle = 1;
        else unite(u, v);
    }
    printf("%s\n", cycle ? "YES" : "NO");
    return 0;
}
