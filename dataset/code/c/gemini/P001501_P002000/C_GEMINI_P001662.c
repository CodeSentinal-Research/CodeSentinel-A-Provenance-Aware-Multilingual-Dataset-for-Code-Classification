#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkBalanced(struct TreeNode* node) {
    if (node == NULL) return 0;
    int l = checkBalanced(node->left);
    if (l == -1) return -1;
    int r = checkBalanced(node->right);
    if (r == -1 || abs(l - r) > 1) return -1;
    return 1 + MAX(l, r);
}

bool isBalanced(struct TreeNode* root) {
    return checkBalanced(root) != -1;
}