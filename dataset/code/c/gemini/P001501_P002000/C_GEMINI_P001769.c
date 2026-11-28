#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* smallestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* res = (int*)malloc(10005 * sizeof(int));
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        int minVal = INT_MAX;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            minVal = MIN(minVal, node->val);
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        res[(*returnSize)++] = minVal;
    }
    free(q);
    return res;
}