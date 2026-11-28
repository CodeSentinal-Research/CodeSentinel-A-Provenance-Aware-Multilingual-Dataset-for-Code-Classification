#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

bool dfs(int u, EdgeNode** adj, int* vis) {
    vis[u] = 1;
    EdgeNode* cur = adj[u];
    while (cur) {
        int v = cur->v;
        if (vis[v] == 1) return true;
        if (vis[v] == 0 && dfs(v, adj, vis)) return true;
        cur = cur->next;
    }
    vis[u] = 2;
    return false;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
            node->v = v;
            node->next = adj[u];
            adj[u] = node;
        }
        int* vis = (int*)calloc(n, sizeof(int));
        bool cycle = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0 && dfs(i, adj, vis)) {
                cycle = true;
                break;
            }
        }
        printf("%s\n", cycle ? "YES" : "NO");
        free(vis);
        free(adj);
    }
    return 0;
}