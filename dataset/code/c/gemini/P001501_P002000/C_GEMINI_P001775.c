#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxAdjacentLevelDiff(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    long long levelSums[10005];
    int numLevels = 0;

    while (tail > head) {
        int size = tail - head;
        long long curSum = 0;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            curSum += node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        levelSums[numLevels++] = curSum;
    }
    free(q);

    long long maxDiff = 0;
    for (int i = 1; i < numLevels; i++) {
        long long diff = llabs(levelSums[i] - levelSums[i - 1]);
        maxDiff = MAX(maxDiff, diff);
    }
    return (int)maxDiff;
}