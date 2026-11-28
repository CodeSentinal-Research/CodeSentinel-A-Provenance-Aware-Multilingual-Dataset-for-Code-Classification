#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int deepestLeavesSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int sum = 0;

    while (tail > head) {
        int size = tail - head;
        sum = 0;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            sum += node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
    }
    free(q);
    return sum;
}