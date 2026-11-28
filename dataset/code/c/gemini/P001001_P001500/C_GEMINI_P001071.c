#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

void dfs(int u, EdgeNode** adj, bool* vis) {
    vis[u] = true;
    EdgeNode* cur = adj[u];
    while (cur) {
        if (!vis[cur->v]) dfs(cur->v, adj, vis);
        cur = cur->next;
    }
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
        bool* vis = (bool*)calloc(n, sizeof(bool));
        int lastV = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                lastV = i;
            }
        }
        for (int i = 0; i < n; i++) vis[i] = false;
        dfs(lastV, adj, vis);
        bool allVis = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) { allVis = false; break; }
        }
        printf("%d\n", allVis ? lastV : -1);
        free(vis);
        free(adj);
    }
    return 0;
}