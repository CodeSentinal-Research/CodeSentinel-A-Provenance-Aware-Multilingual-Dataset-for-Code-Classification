#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode** splitBST(struct TreeNode* root, int target, int* returnSize) {
    *returnSize = 2;
    struct TreeNode** res = (struct TreeNode**)malloc(2 * sizeof(struct TreeNode*));
    if (root == NULL) {
        res[0] = NULL; res[1] = NULL;
        return res;
    }

    if (root->val <= target) {
        int subSize;
        struct TreeNode** sub = splitBST(root->right, target, &subSize);
        root->right = sub[0];
        res[0] = root;
        res[1] = sub[1];
        free(sub);
    } else {
        int subSize;
        struct TreeNode** sub = splitBST(root->left, target, &subSize);
        root->left = sub[1];
        res[0] = sub[0];
        res[1] = root;
        free(sub);
    }
    return res;
}