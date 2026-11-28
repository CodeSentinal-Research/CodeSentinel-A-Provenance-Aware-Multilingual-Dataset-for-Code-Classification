#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderCumulative(struct TreeNode* node, int* curSum) {
    if (node == NULL) return;
    inorderCumulative(node->left, curSum);
    *curSum += node->val;
    node->val = *curSum;
    inorderCumulative(node->right, curSum);
}

struct TreeNode* bstToCumulative(struct TreeNode* root) {
    int curSum = 0;
    inorderCumulative(root, &curSum);
    return root;
}