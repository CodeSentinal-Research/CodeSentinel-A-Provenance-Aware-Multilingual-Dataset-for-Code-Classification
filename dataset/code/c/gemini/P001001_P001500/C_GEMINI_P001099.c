#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int* parent = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) parent[i] = i;
        bool cycle = false;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int ru = findSet(parent, u), rv = findSet(parent, v);
            if (ru == rv) {
                cycle = true;
            } else {
                parent[ru] = rv;
            }
        }
        printf("%s\n", cycle ? "YES" : "NO");
        free(parent);
    }
    return 0;
}