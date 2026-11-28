#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

bool dfs(int u, int count, int n, EdgeNode** adj, bool* vis) {
    if (count == n) {
        EdgeNode* cur = adj[u];
        while (cur) {
            if (cur->v == 0) return true;
            cur = cur->next;
        }
        return false;
    }
    vis[u] = true;
    EdgeNode* cur = adj[u];
    while (cur) {
        if (!vis[cur->v] && dfs(cur->v, count + 1, n, adj, vis)) return true;
        cur = cur->next;
    }
    vis[u] = false;
    return false;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n1->v = v; n1->next = adj[u]; adj[u] = n1;
            EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n2->v = u; n2->next = adj[v]; adj[v] = n2;
        }
        bool* vis = (bool*)calloc(n, sizeof(bool));
        printf("%s\n", dfs(0, 1, n, adj, vis) ? "YES" : "NO");
        free(vis);
        free(adj);
    }
    return 0;
}