#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsAlternating(struct TreeNode* node, int parentVal, int hasParent, int curLen, int* maxLen) {
    if (node == NULL) return;
    if (hasParent && (abs(node->val % 2) != abs(parentVal % 2))) {
        curLen++;
    } else {
        curLen = 1;
    }
    *maxLen = MAX(*maxLen, curLen);
    dfsAlternating(node->left, node->val, 1, curLen, maxLen);
    dfsAlternating(node->right, node->val, 1, curLen, maxLen);
}

int longestAlternatingPath(struct TreeNode* root) {
    int maxLen = 0;
    dfsAlternating(root, 0, 0, 0, &maxLen);
    return maxLen;
}