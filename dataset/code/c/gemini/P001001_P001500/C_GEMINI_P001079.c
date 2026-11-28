#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    int u, v;
} Bridge;

int cmpBridge(const void* a, const void* b) {
    Bridge* b1 = (Bridge*)a;
    Bridge* b2 = (Bridge*)b;
    if (b1->u != b2->u) return b1->u - b2->u;
    return b1->v - b2->v;
}

int timer_val = 0;

void dfs(int u, int p, EdgeNode** adj, int* tin, int* low, Bridge* bridges, int* bCount) {
    tin[u] = low[u] = timer_val++;
    EdgeNode* cur = adj[u];
    while (cur) {
        int v = cur->v;
        if (v != p) {
            if (tin[v] != -1) {
                if (tin[v] < low[u]) low[u] = tin[v];
            } else {
                dfs(v, u, adj, tin, low, bridges, bCount);
                if (low[v] < low[u]) low[u] = low[v];
                if (low[v] > tin[u]) {
                    bridges[*bCount].u = u < v ? u : v;
                    bridges[*bCount].v = u > v ? u : v;
                    (*bCount)++;
                }
            }
        }
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
        int* tin = (int*)malloc(n * sizeof(int));
        int* low = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) { tin[i] = -1; low[i] = -1; }
        Bridge* bridges = (Bridge*)malloc(m * sizeof(Bridge));
        int bCount = 0;
        timer_val = 0;

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) dfs(i, -1, adj, tin, low, bridges, &bCount);
        }
        qsort(bridges, bCount, sizeof(Bridge), cmpBridge);
        for (int i = 0; i < bCount; i++) {
            printf("%d %d\n", bridges[i].u, bridges[i].v);
        }
        free(tin);
        free(low);
        free(bridges);
        free(adj);
    }
    return 0;
}