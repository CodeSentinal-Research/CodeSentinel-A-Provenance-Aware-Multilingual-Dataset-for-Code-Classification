#include <stdio.h>

int n, e;
int adj[20][20], path[20];

void dfs(int u, int len) {
    path[len] = u;
    if (u == n - 1) {
        for (int i = 0; i <= len; i++) printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) dfs(v, len + 1);
    }
}

int main() {
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }
    dfs(0, 0);
    return 0;
}
