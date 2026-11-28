#include <stdlib.h>

typedef struct EdgeNode {
    int v;
    struct EdgeNode* next;
} EdgeNode;

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    EdgeNode** adj = (EdgeNode**)calloc(numCourses, sizeof(EdgeNode*));
    int* inDeg = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1], v = prerequisites[i][0];
        EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
        node->v = v; node->next = adj[u]; adj[u] = node;
        inDeg[v]++;
    }
    int* q = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDeg[i] == 0) q[tail++] = i;
    }
    int* order = (int*)malloc(numCourses * sizeof(int));
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
    free(inDeg);
    free(q);
    free(adj);
    if (oSize == numCourses) {
        *returnSize = numCourses;
        return order;
    } else {
        *returnSize = 0;
        free(order);
        return NULL;
    }
}