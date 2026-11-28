#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodesRot(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodesRot(node->left) + countNodesRot(node->right);
}

int minRotationsToBalance(struct TreeNode* root) {
    int n = countNodesRot(root);
    if (n <= 2) return 0;

    int h = (int)(log2(n + 1));
    int m = (1 << h) - 1;
    int totalRotations = n - m;

    m /= 2;
    while (m > 0) {
        totalRotations += m;
        m /= 2;
    }
    return totalRotations;
}