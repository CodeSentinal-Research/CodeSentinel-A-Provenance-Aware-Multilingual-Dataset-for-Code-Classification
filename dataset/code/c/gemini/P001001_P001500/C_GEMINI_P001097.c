#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) == 2) {
        int* parent = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) parent[i] = i;

        char op[32];
        while (q--) {
            scanf("%s", op);
            if (strcmp(op, "UNION") == 0) {
                int u, v;
                scanf("%d %d", &u, &v);
                int ru = findSet(parent, u), rv = findSet(parent, v);
                if (ru != rv) parent[ru] = rv;
            } else if (strcmp(op, "FIND") == 0) {
                int u;
                scanf("%d", &u);
                printf("%d\n", findSet(parent, u));
            } else if (strcmp(op, "CONNECTED") == 0) {
                int u, v;
                scanf("%d %d", &u, &v);
                printf("%s\n", findSet(parent, u) == findSet(parent, v) ? "YES" : "NO");
            }
        }
        free(parent);
    }
    return 0;
}