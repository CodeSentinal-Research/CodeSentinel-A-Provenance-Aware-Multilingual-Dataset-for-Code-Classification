#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            EdgeNode* n1 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n1->v = v; n1->w = w; n1->next = adj[u]; adj[u] = n1;
            EdgeNode* n2 = (EdgeNode*)malloc(sizeof(EdgeNode));
            n2->v = u; n2->w = w; n2->next = adj[v]; adj[v] = n2;
        }
        int src;
        scanf("%d", &src);
        long long* dist = (long long*)malloc(n * sizeof(long long));
        bool* vis = (bool*)calloc(n, sizeof(bool));
        for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
        dist[src] = 0;

        for (int iter = 0; iter < n; iter++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            if (u == -1 || dist[u] == LLONG_MAX) break;
            vis[u] = true;
            EdgeNode* cur = adj[u];
            while (cur) {
                if (dist[u] + cur->w < dist[cur->v]) {
                    dist[cur->v] = dist[u] + cur->w;
                }
                cur = cur->next;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld%s", dist[i] == LLONG_MAX ? -1 : dist[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
        free(dist);
        free(vis);
        free(adj);
    }
    return 0;
}