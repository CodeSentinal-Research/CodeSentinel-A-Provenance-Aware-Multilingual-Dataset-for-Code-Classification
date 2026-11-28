#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int timer_val = 0;

void dfs(int u, int p, EdgeNode** adj, int* tin, int* low, int** bridges, int* bCount) {
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
                    bridges[*bCount] = (int*)malloc(2 * sizeof(int));
                    bridges[*bCount][0] = u;
                    bridges[*bCount][1] = v;
                    (*bCount)++;
                }
            }
        }
        cur = cur->next;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0], v = connections[i][1];
        EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
        n1->v = v; n1->next = adj[u]; adj[u] = n1;
        EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
        n2->v = u; n2->next = adj[v]; adj[v] = n2;
    }
    int* tin = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { tin[i] = -1; low[i] = -1; }
    int** bridges = (int**)malloc(connectionsSize * sizeof(int*));
    int bCount = 0;
    timer_val = 0;

    dfs(0, -1, adj, tin, low, bridges, &bCount);

    *returnSize = bCount;
    *returnColumnSizes = (int*)malloc(bCount * sizeof(int));
    for (int i = 0; i < bCount; i++) (*returnColumnSizes)[i] = 2;

    free(tin);
    free(low);
    free(adj);
    return bridges;
}