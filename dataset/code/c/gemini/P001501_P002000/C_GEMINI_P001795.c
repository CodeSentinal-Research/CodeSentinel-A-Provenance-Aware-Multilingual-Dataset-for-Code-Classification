#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildBST(int* nums, int l, int r) {
    if (l > r) return NULL;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = buildBST(nums, l, mid - 1);
    root->right = buildBST(nums, mid + 1, r);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}