#include <stdlib.h>

#define MOD 1000000007

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

long long combArr[1005][1005];

void precompute(void) {
    for (int i = 0; i <= 1000; i++) {
        combArr[i][0] = combArr[i][i] = 1;
        for (int j = 1; j < i; j++) {
            combArr[i][j] = (combArr[i - 1][j - 1] + combArr[i - 1][j]) % MOD;
        }
    }
}

void dfsSeqs(struct TreeNode* node, long long* ways, int* size) {
    if (node == NULL) {
        *ways = 1;
        *size = 0;
        return;
    }
    long long lWays, rWays;
    int lSize, rSize;
    dfsSeqs(node->left, &lWays, &lSize);
    dfsSeqs(node->right, &rWays, &rSize);

    int total = lSize + rSize;
    long long c = combArr[total][lSize];
    *ways = (((lWays * rWays) % MOD) * c) % MOD;
    *size = total + 1;
}

int countValidInsertionSeqs(struct TreeNode* root) {
    precompute();
    long long ways;
    int size;
    dfsSeqs(root, &ways, &size);
    return (int)ways;
}