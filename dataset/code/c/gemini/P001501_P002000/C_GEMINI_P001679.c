#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    long long maxSum = LLONG_MIN;
    int maxLevel = 1, curLevel = 1;

    while (tail > head) {
        int size = tail - head;
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            sum += node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = curLevel;
        }
        curLevel++;
    }
    free(q);
    return maxLevel;
}