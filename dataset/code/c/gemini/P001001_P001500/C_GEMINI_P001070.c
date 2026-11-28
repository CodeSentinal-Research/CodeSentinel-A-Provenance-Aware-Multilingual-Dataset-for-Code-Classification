#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)calloc(graphSize, sizeof(int));
    int* q = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (color[i] == 0) {
            int head = 0, tail = 0;
            q[tail++] = i;
            color[i] = 1;
            while (head < tail) {
                int u = q[head++];
                for (int j = 0; j < graphColSize[u]; j++) {
                    int v = graph[u][j];
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q[tail++] = v;
                    } else if (color[v] == color[u]) {
                        free(color);
                        free(q);
                        return false;
                    }
                }
            }
        }
    }
    free(color);
    free(q);
    return true;
}