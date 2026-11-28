#include <stdlib.h>
#include <stdbool.h>

bool dfs(int u, int** graph, int* graphColSize, int* color) {
    color[u] = 1;
    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];
        if (color[v] == 1 || (color[v] == 0 && !dfs(v, graph, graphColSize, color))) {
            return false;
        }
    }
    color[u] = 2;
    return true;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int* color = (int*)calloc(graphSize, sizeof(int));
    int* res = (int*)malloc(graphSize * sizeof(int));
    int rSize = 0;

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == 2 || (color[i] == 0 && dfs(i, graph, graphColSize, color))) {
            res[rSize++] = i;
        }
    }

    *returnSize = rSize;
    free(color);
    return res;
}