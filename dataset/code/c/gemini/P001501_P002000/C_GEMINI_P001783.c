#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countTreeNodes(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countTreeNodes(node->left) + countTreeNodes(node->right);
}

int dfsCentroid(struct TreeNode* node, int totalNodes, int* centroid) {
    if (node == NULL) return 0;
    int l = dfsCentroid(node->left, totalNodes, centroid);
    int r = dfsCentroid(node->right, totalNodes, centroid);
    int parentSize = totalNodes - (1 + l + r);

    if (l <= totalNodes / 2 && r <= totalNodes / 2 && parentSize <= totalNodes / 2) {
        *centroid = node->val;
    }

    return 1 + l + r;
}

int findCentroid(struct TreeNode* root) {
    int totalNodes = countTreeNodes(root);
    int centroid = -1;
    dfsCentroid(root, totalNodes, &centroid);
    return centroid;
}