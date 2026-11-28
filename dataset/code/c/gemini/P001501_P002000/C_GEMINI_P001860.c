#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct NodeDesc {
    int sum;
    int id;
};

int cmpDesc(const void* a, const void* b) {
    return ((struct NodeDesc*)b)->sum - ((struct NodeDesc*)a)->sum;
}

struct TreeNode* insertBSTMat(struct TreeNode* node, int val) {
    if (node == NULL) {
        struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        n->val = val; n->left = NULL; n->right = NULL;
        return n;
    }
    if (val < node->val) node->left = insertBSTMat(node->left, val);
    else node->right = insertBSTMat(node->right, val);
    return node;
}

struct TreeNode* bstFromAncestorMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return NULL;
    struct NodeDesc* desc = (struct NodeDesc*)malloc(matrixSize * sizeof(struct NodeDesc));
    for (int i = 0; i < matrixSize; i++) {
        int sum = 0;
        for (int j = 0; j < matrixSize; j++) sum += matrix[i][j];
        desc[i].sum = sum;
        desc[i].id = i;
    }
    qsort(desc, matrixSize, sizeof(struct NodeDesc), cmpDesc);

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = desc[0].id; root->left = NULL; root->right = NULL;
    for (int i = 1; i < matrixSize; i++) {
        insertBSTMat(root, desc[i].id);
    }
    free(desc);
    return root;
}