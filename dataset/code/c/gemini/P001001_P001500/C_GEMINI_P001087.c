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
            EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n1->v = v; n1->next = adj[u]; adj[u] = n1;
            EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n2->v = u; n2->next = adj[v]; adj[v] = n2;
        }
        if (m != n - 1) {
            printf("NO\n");
        } else {
            bool* vis = (bool*)calloc(n, sizeof(bool));
            dfs(0, adj, vis);
            bool allVis = true;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) { allVis = false; break; }
            }
            printf("%s\n", allVis ? "YES" : "NO");
            free(vis);
        }
        free(adj);
    }
    return 0;
}