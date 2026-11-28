#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    double* res = (double*)malloc(10005 * sizeof(double));
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        double levelSum = 0;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            levelSum += node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        res[(*returnSize)++] = levelSum / size;
    }
    free(q);
    return res;
}