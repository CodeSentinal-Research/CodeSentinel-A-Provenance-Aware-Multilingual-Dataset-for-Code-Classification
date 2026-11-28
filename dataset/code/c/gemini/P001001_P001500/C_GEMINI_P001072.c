#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

void dfs1(int u, EdgeNode** adj, bool* vis, int* order, int* oSize) {
    vis[u] = true;
    EdgeNode* cur = adj[u];
    while (cur) {
        if (!vis[cur->v]) dfs1(cur->v, adj, vis, order, oSize);
        cur = cur->next;
    }
    order[(*oSize)++] = u;
}

void dfs2(int u, EdgeNode** radj, bool* vis) {
    vis[u] = true;
    EdgeNode* cur = radj[u];
    while (cur) {
        if (!vis[cur->v]) dfs2(cur->v, radj, vis);
        cur = cur->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        EdgeNode** radj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* node1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            node1->v = v;
            node1->next = adj[u];
            adj[u] = node1;

            EdgeNode* node2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            node2->v = u;
            node2->next = radj[v];
            radj[v] = node2;
        }
        bool* vis = (bool*)calloc(n, sizeof(bool));
        int* order = (int*)malloc(n * sizeof(int));
        int oSize = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i, adj, vis, order, &oSize);
        }
        for (int i = 0; i < n; i++) vis[i] = false;
        int scc = 0;
        for (int i = oSize - 1; i >= 0; i--) {
            int u = order[i];
            if (!vis[u]) {
                dfs2(u, radj, vis);
                scc++;
            }
        }
        printf("%d\n", scc);
        free(vis);
        free(order);
        free(adj);
        free(radj);
    }
    return 0;
}