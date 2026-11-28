#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsKEdges(struct TreeNode* node, int edges, int k) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return edges == k ? 1 : 0;
    return dfsKEdges(node->left, edges + 1, k) + dfsKEdges(node->right, edges + 1, k);
}

int countPathsKEdges(struct TreeNode* root, int k) {
    return dfsKEdges(root, 0, k);
}