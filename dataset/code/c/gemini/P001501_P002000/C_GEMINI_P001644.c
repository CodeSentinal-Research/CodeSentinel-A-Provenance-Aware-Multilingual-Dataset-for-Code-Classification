#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isLeafC(struct TreeNode* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

void addLeavesC(struct TreeNode* node, int* res, int* idx) {
    if (isLeafC(node)) {
        res[(*idx)++] = node->val;
        return;
    }
    if (node->left) addLeavesC(node->left, res, idx);
    if (node->right) addLeavesC(node->right, res, idx);
}

int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    int idx = 0;
    if (root == NULL) { *returnSize = 0; return res; }

    if (!isLeafC(root)) res[idx++] = root->val;

    struct TreeNode* cur = root->left;
    while (cur) {
        if (!isLeafC(cur)) res[idx++] = cur->val;
        cur = cur->left ? cur->left : cur->right;
    }

    addLeavesC(root, res, &idx);

    int st[10005], top = 0;
    cur = root->right;
    while (cur) {
        if (!isLeafC(cur)) st[top++] = cur->val;
        cur = cur->right ? cur->right : cur->left;
    }
    while (top > 0) res[idx++] = st[--top];

    *returnSize = idx;
    return res;
}