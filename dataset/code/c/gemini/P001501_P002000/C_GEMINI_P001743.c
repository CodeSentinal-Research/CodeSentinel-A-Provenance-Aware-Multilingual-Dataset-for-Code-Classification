#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int firstNonFullNode(struct TreeNode* root) {
    if (root == NULL) return -1;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        struct TreeNode* node = q[head++];
        if (node->left == NULL || node->right == NULL) {
            int ans = node->val;
            free(q);
            return ans;
        }
        q[tail++] = node->left;
        q[tail++] = node->right;
    }
    free(q);
    return -1;
}