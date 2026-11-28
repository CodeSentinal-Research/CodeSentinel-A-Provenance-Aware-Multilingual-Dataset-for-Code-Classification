#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsValid(struct TreeNode* node, long long low, long long high) {
    if (node == NULL) return true;
    if (node->val <= low || node->val >= high) return false;
    return dfsValid(node->left, low, node->val) && dfsValid(node->right, node->val, high);
}

bool isValidBST(struct TreeNode* root) {
    return dfsValid(root, LLONG_MIN, LLONG_MAX);
}