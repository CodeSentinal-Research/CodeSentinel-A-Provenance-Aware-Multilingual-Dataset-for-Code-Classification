#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

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
        int src;
        scanf("%d", &src);
        bool* vis = (bool*)calloc(n, sizeof(bool));
        int* q = (int*)malloc(n * sizeof(int));
        int head = 0, tail = 0;
        q[tail++] = src;
        vis[src] = true;
        int count = 0;

        while (head < tail) {
            int u = q[head++];
            count++;
            EdgeNode* cur = adj[u];
            while (cur) {
                if (!vis[cur->v]) {
                    vis[cur->v] = true;
                    q[tail++] = cur->v;
                }
                cur = cur->next;
            }
        }
        printf("%d\n", count);
        free(vis);
        free(q);
        free(adj);
    }
    return 0;
}