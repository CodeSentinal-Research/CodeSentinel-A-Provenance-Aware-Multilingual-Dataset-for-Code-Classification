#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfsAddRow(struct TreeNode* node, int val, int depth, int curDepth) {
    if (node == NULL) return;
    if (curDepth == depth - 1) {
        struct TreeNode* l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        l->val = val; l->left = node->left; l->right = NULL;
        node->left = l;

        struct TreeNode* r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        r->val = val; r->left = NULL; r->right = node->right;
        node->right = r;
        return;
    }
    dfsAddRow(node->left, val, depth, curDepth + 1);
    dfsAddRow(node->right, val, depth, curDepth + 1);
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    if (depth == 1) {
        struct TreeNode* newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newRoot->val = val; newRoot->left = root; newRoot->right = NULL;
        return newRoot;
    }
    dfsAddRow(root, val, depth, 1);
    return root;
}