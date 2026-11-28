#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        int* inDeg = (int*)calloc(n, sizeof(int));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
            node->v = v;
            node->next = adj[u];
            adj[u] = node;
            inDeg[v]++;
        }
        int* q = (int*)malloc(n * sizeof(int));
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) q[tail++] = i;
        }
        int* order = (int*)malloc(n * sizeof(int));
        int oSize = 0;
        while (head < tail) {
            int u = q[head++];
            order[oSize++] = u;
            EdgeNode* cur = adj[u];
            while (cur) {
                if (--inDeg[cur->v] == 0) q[tail++] = cur->v;
                cur = cur->next;
            }
        }
        for (int i = 0; i < oSize; i++) {
            printf("%d%s", order[i], (i == oSize - 1 ? "" : " "));
        }
        printf("\n");
        free(inDeg);
        free(q);
        free(order);
        free(adj);
    }
    return 0;
}