#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int kthLargest(struct TreeNode* root, int k) {
    struct TreeNode** stack = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int top = -1;
    struct TreeNode* cur = root;

    while (cur != NULL || top >= 0) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->right;
        }
        cur = stack[top--];
        if (--k == 0) {
            int ans = cur->val;
            free(stack);
            return ans;
        }
        cur = cur->left;
    }
    free(stack);
    return -1;
}