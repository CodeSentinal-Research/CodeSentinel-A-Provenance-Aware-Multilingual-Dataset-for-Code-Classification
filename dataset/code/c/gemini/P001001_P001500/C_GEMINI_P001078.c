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
        bool* vis = (bool*)calloc(n, sizeof(bool));
        long long* key = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) key[i] = LLONG_MAX;
        key[0] = 0;
        long long total = 0;

        for (int iter = 0; iter < n; iter++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }
            if (u == -1 || key[u] == LLONG_MAX) break;
            vis[u] = true;
            total += key[u];
            EdgeNode* cur = adj[u];
            while (cur) {
                if (!vis[cur->v] && cur->w < key[cur->v]) {
                    key[cur->v] = cur->w;
                }
                cur = cur->next;
            }
        }
        printf("%lld\n", total);
        free(vis);
        free(key);
        free(adj);
    }
    return 0;
}