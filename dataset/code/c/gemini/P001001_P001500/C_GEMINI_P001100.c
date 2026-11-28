#include <stdio.h>
#include <stdlib.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) == 2) {
        int* parent = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) parent[i] = i;

        while (q--) {
            int type, u, v;
            scanf("%d %d %d", &type, &u, &v);
            if (type == 1) {
                int ru = findSet(parent, u), rv = findSet(parent, v);
                if (ru != rv) parent[ru] = rv;
            } else {
                printf("%s\n", findSet(parent, u) == findSet(parent, v) ? "YES" : "NO");
            }
        }
        free(parent);
    }
    return 0;
}