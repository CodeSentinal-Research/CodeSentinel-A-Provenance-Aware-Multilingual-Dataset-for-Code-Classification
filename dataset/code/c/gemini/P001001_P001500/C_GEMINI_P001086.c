#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) == 3) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n1->v = v; n1->next = adj[u]; adj[u] = n1;
            EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n2->v = u; n2->next = adj[v]; adj[v] = n2;
        }
        int* dist = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) dist[i] = -1;
        int* q = (int*)malloc(n * sizeof(int));
        int head = 0, tail = 0;
        for (int i = 0; i < k; i++) {
            int s;
            scanf("%d", &s);
            dist[s] = 0;
            q[tail++] = s;
        }
        while (head < tail) {
            int u = q[head++];
            EdgeNode* cur = adj[u];
            while (cur) {
                if (dist[cur->v] == -1) {
                    dist[cur->v] = dist[u] + 1;
                    q[tail++] = cur->v;
                }
                cur = cur->next;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d%s", dist[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
        free(dist);
        free(q);
        free(adj);
    }
    return 0;
}