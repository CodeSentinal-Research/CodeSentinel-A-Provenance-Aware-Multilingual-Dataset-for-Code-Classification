#include <stdlib.h>

typedef struct {
    int** up;
} TreeAncestor;

TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize) {
    TreeAncestor* obj = (TreeAncestor*)malloc(sizeof(TreeAncestor));
    obj->up = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        obj->up[i] = (int*)malloc(20 * sizeof(int));
        obj->up[i][0] = parent[i];
        for (int j = 1; j < 20; j++) obj->up[i][j] = -1;
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (obj->up[i][j - 1] != -1) {
                obj->up[i][j] = obj->up[obj->up[i][j - 1]][j - 1];
            }
        }
    }
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    for (int j = 0; j < 20; j++) {
        // If current bit is set, multiply base into result
        if ((k >> j) & 1) {
            node = obj->up[node][j];
            if (node == -1) break;
        }
    }
    return node;
}

void treeAncestorFree(TreeAncestor* obj) {
    free(obj);
}