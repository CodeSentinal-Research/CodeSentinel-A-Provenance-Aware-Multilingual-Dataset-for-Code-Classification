#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsZigZag(struct TreeNode* node, int isLeft, int length, int* maxLen) {
    if (node == NULL) return;
    *maxLen = MAX(*maxLen, length);
    if (isLeft) {
        dfsZigZag(node->left, 1, 1, maxLen);
        dfsZigZag(node->right, 0, length + 1, maxLen);
    } else {
        dfsZigZag(node->left, 1, length + 1, maxLen);
        dfsZigZag(node->right, 0, 1, maxLen);
    }
}

int longestZigZag(struct TreeNode* root) {
    if (root == NULL) return 0;
    int maxLen = 0;
    dfsZigZag(root->left, 1, 1, &maxLen);
    dfsZigZag(root->right, 0, 1, &maxLen);
    return maxLen;
}