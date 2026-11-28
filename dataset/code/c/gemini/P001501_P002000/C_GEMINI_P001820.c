#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderKeyRank(struct TreeNode* node, int rank, int* curRank, int* ans) {
    if (node == NULL || *ans != -1) return;
    inorderKeyRank(node->left, rank, curRank, ans);
    (*curRank)++;
    if (*curRank == rank) {
        *ans = node->val;
        return;
    }
    inorderKeyRank(node->right, rank, curRank, ans);
}

int keyWithRank(struct TreeNode* root, int rank) {
    int curRank = 0, ans = -1;
    inorderKeyRank(root, rank, &curRank, &ans);
    return ans;
}