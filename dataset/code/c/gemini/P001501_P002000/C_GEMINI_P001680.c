#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* largestValues(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(10005 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) return res;

    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        int maxVal = INT_MIN;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            maxVal = MAX(maxVal, node->val);
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        res[(*returnSize)++] = maxVal;
    }
    free(q);
    return res;
}