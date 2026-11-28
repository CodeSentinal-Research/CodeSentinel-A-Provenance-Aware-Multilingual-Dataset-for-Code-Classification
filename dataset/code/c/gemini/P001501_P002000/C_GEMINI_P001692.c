#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsConsecutive(struct TreeNode* node, struct TreeNode* parent, int length, int* maxLen) {
    if (node == NULL) return;
    if (parent != NULL && node->val == parent->val + 1) {
        length++;
    } else {
        length = 1;
    }
    *maxLen = MAX(*maxLen, length);
    dfsConsecutive(node->left, node, length, maxLen);
    dfsConsecutive(node->right, node, length, maxLen);
}

int longestConsecutive(struct TreeNode* root) {
    int maxLen = 0;
    dfsConsecutive(root, NULL, 0, &maxLen);
    return maxLen;
}