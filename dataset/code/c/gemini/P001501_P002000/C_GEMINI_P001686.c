#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int levelOrderPredecessor(struct TreeNode* root, int targetVal) {
    if (root == NULL) return -1;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int prevVal = -1;

    while (tail > head) {
        struct TreeNode* node = q[head++];
        if (node->val == targetVal) {
            free(q);
            return prevVal;
        }
        prevVal = node->val;
        if (node->left) q[tail++] = node->left;
        if (node->right) q[tail++] = node->right;
    }
    free(q);
    return -1;
}