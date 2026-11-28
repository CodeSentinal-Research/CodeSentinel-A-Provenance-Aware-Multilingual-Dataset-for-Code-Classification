#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int timer_val = 0;

void dfs(int u, int p, EdgeNode** adj, int* tin, int* low, bool* isAp) {
    tin[u] = low[u] = timer_val++;
    int children = 0;
    EdgeNode* cur = adj[u];
    while (cur) {
        int v = cur->v;
        if (v != p) {
            if (tin[v] != -1) {
                if (tin[v] < low[u]) low[u] = tin[v];
            } else {
                dfs(v, u, adj, tin, low, isAp);
                if (low[v] < low[u]) low[u] = low[v];
                if (low[v] >= tin[u] && p != -1) isAp[u] = true;
                children++;
            }
        }
        cur = cur->next;
    }
    if (p == -1 && children > 1) isAp[u] = true;
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
        int* tin = (int*)malloc(n * sizeof(int));
        int* low = (int*)malloc(n * sizeof(int));
        bool* isAp = (bool*)calloc(n, sizeof(bool));
        for (int i = 0; i < n; i++) { tin[i] = -1; low[i] = -1; }
        timer_val = 0;

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) dfs(i, -1, adj, tin, low, isAp);
        }
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (isAp[i]) {
                if (!first) printf(" ");
                printf("%d", i);
                first = false;
            }
        }
        printf("\n");
        free(tin);
        free(low);
        free(isAp);
        free(adj);
    }
    return 0;
}