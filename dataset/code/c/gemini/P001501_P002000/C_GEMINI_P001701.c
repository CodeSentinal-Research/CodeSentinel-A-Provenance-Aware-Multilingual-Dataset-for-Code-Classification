#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode** q = (struct TreeNode**)malloc(100005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    root->val = 0;

    while (tail > head) {
        int size = tail - head;
        long long levelSum = 0;
        for (int i = head; i < tail; i++) {
            if (q[i]->left) levelSum += q[i]->left->val;
            if (q[i]->right) levelSum += q[i]->right->val;
        }

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            int siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
            if (node->left) {
                node->left->val = (int)(levelSum - siblingSum);
                q[tail++] = node->left;
            }
            if (node->right) {
                node->right->val = (int)(levelSum - siblingSum);
                q[tail++] = node->right;
            }
        }
    }
    free(q);
    return root;
}