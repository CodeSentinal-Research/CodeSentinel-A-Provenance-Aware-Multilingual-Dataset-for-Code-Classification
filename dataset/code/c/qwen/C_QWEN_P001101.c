#include <stdio.h>
int parent[100001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { int a = find(i), b = find(j); parent[a] = b; }
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<=n; i++) parent[i] = i;
    int u, v, ans_u = -1, ans_v = -1;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &u, &v);
        if(find(u) == find(v)) { ans_u = u; ans_v = v; }
        else unite(u, v);
    }
    printf("%d %d\n", ans_u, ans_v);
    return 0;
}
