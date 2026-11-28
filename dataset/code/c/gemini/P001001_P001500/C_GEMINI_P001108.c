#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int main() {
    int n, m, q;
    if (scanf("%d %d %d", &n, &m, &q) == 3) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
            node->v = v;
            node->next = adj[u];
            adj[u] = node;
        }

        while (q--) {
            int src, dst;
            scanf("%d %d", &src, &dst);
            bool* vis = (bool*)calloc(n, sizeof(bool));
            int* queue = (int*)malloc(n * sizeof(int));
            int head = 0, tail = 0;
            queue[tail++] = src;
            vis[src] = true;
            bool found = false;

            while (head < tail) {
                int u = queue[head++];
                if (u == dst) { found = true; break; }
                EdgeNode* cur = adj[u];
                while (cur) {
                    if (!vis[cur->v]) {
                        vis[cur->v] = true;
                        queue[tail++] = cur->v;
                    }
                    cur = cur->next;
                }
            }
            printf("%s\n", found ? "YES" : "NO");
            free(vis);
            free(queue);
        }
        free(adj);
    }
    return 0;
}