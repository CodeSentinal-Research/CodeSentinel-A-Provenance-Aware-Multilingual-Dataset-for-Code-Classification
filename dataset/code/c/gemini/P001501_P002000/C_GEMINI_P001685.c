#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int levelOrderSuccessor(struct TreeNode* root, int targetVal) {
    if (root == NULL) return -1;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    bool found = false;

    while (tail > head) {
        struct TreeNode* node = q[head++];
        if (found) {
            int ans = node->val;
            free(q);
            return ans;
        }
        if (node->val == targetVal) found = true;
        if (node->left) q[tail++] = node->left;
        if (node->right) q[tail++] = node->right;
    }
    free(q);
    return -1;
}