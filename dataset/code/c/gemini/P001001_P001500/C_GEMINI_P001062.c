#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int* inDegree = (int*)calloc(n, sizeof(int));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            inDegree[v]++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) count++;
        }
        printf("%d\n", count);
        free(inDegree);
    }
    return 0;
}