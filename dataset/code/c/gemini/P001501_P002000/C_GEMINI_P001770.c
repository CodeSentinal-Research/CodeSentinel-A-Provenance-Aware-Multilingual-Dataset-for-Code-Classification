#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* replaceWithLevelSum(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        int levelSum = 0;
        for (int i = head; i < tail; i++) {
            levelSum += q[i]->val;
        }
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            node->val = levelSum;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
    }
    free(q);
    return root;
}