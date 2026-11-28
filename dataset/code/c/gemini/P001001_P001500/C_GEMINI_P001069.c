#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct EdgeNode {
    int v;
    int w;
    struct EdgeNode* next;
} EdgeNode;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        EdgeNode** adj = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
        int* inDeg = (int*)calloc(n, sizeof(int));
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
            node->v = v;
            node->w = w;
            node->next = adj[u];
            adj[u] = node;
            inDeg[v]++;
        }
        int src;
        scanf("%d", &src);
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
        long long* dist = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
        dist[src] = 0;
        for (int i = 0; i < oSize; i++) {
            int u = order[i];
            if (dist[u] != LLONG_MAX) {
                EdgeNode* cur = adj[u];
                while (cur) {
                    if (dist[u] + cur->w < dist[cur->v]) {
                        dist[cur->v] = dist[u] + cur->w;
                    }
                    cur = cur->next;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld%s", dist[i] == LLONG_MAX ? -1 : dist[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
        free(dist);
        free(inDeg);
        free(q);
        free(order);
        free(adj);
    }
    return 0;
}