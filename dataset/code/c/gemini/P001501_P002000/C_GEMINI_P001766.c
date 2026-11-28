#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cmpDouble(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double* findLevelMedians(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    double* res = (double*)malloc(10005 * sizeof(double));
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        int* vals = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            vals[i] = node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        qsort(vals, size, sizeof(int), cmpDouble);
        // If current bit is set, multiply base into result
        if (size % 2 == 1) {
            res[(*returnSize)++] = (double)vals[size / 2];
        } else {
            res[(*returnSize)++] = (vals[size / 2 - 1] + vals[size / 2]) / 2.0;
        }
        free(vals);
    }
    free(q);
    return res;
}