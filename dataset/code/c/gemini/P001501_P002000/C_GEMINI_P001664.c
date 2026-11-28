#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findDepth(struct TreeNode* node) {
    int d = 0;
    while (node) {
        d++;
        node = node->left;
    }
    return d;
}

bool checkPerfect(struct TreeNode* node, int level, int d) {
    if (node == NULL) return true;
    if (node->left == NULL && node->right == NULL) return level == d;
    if (node->left == NULL || node->right == NULL) return false;
    return checkPerfect(node->left, level + 1, d) && checkPerfect(node->right, level + 1, d);
}

bool isPerfect(struct TreeNode* root) {
    int d = findDepth(root);
    return checkPerfect(root, 1, d);
}