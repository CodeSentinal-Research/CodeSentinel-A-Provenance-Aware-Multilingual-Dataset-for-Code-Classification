#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

void bfs(int src, int n, EdgeNode** adj, int* farthest, int* maxDist) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = -1;
    dist[src] = 0;
    int* q = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0;
    q[tail++] = src;
    *farthest = src;
    *maxDist = 0;

    while (head < tail) {
        int u = q[head++];
        EdgeNode* cur = adj[u];
        while (cur) {
            if (dist[cur->v] == -1) {
                dist[cur->v] = dist[u] + 1;
                q[tail++] = cur->v;
                if (dist[cur->v] > *maxDist) {
                    *maxDist = dist[cur->v];
                    *farthest = cur->v;
                }
            }
            cur = cur->next;
        }
    }
    free(dist);
    free(q);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n <= 1) {
            printf("0\n");
            return 0;
        }
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n1->v = v; n1->next = adj[u]; adj[u] = n1;
            EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n2->v = u; n2->next = adj[v]; adj[v] = n2;
        }
        int u, d1, v, diam;
        bfs(0, n, adj, &u, &d1);
        bfs(u, n, adj, &v, &diam);
        printf("%d\n", diam);
        free(adj);
    }
    return 0;
}