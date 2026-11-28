#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsLongest(struct TreeNode* node, int* path, int len, int* longest, int* maxLen) {
    if (node == NULL) return;
    path[len] = node->val;
    if (node->left == NULL && node->right == NULL) {
        if (len + 1 > *maxLen) {
            *maxLen = len + 1;
            for (int i = 0; i <= len; i++) longest[i] = path[i];
        }
    } else {
        dfsLongest(node->left, path, len + 1, longest, maxLen);
        dfsLongest(node->right, path, len + 1, longest, maxLen);
    }
}

int* longestPath(struct TreeNode* root, int* returnSize) {
    int* longest = (int*)malloc(10005 * sizeof(int));
    int path[10005];
    *returnSize = 0;
    dfsLongest(root, path, 0, longest, returnSize);
    return longest;
}