#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverseInorderGST(struct TreeNode* node, int* curSum) {
    if (node == NULL) return;
    reverseInorderGST(node->right, curSum);
    *curSum += node->val;
    node->val = *curSum;
    reverseInorderGST(node->left, curSum);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    int curSum = 0;
    reverseInorderGST(root, &curSum);
    return root;
}