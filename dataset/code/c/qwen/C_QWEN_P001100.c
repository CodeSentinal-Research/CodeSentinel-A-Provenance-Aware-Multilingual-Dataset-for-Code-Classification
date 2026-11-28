#include <stdio.h>
int parent[200001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { int a = find(i), b = find(j); parent[a] = b; }
int main() {
    int n, q; scanf("%d%d", &n, &q);
    for(int i=0; i<=n; i++) parent[i] = i;
    while(q--) {
        char op[10]; int u, v; scanf("%s%d%d", op, &u, &v);
        if(op[0] == 'A') unite(u, v);
        else printf("%s\n", find(u) == find(v) ? "YES" : "NO");
    }
    return 0;
}
