#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildOBSTTree(int* keys, int rootIdx[105][105], int i, int j) {
    if (i > j) return NULL;
    int r = rootIdx[i][j];
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = keys[r];
    node->left = buildOBSTTree(keys, rootIdx, i, r - 1);
    node->right = buildOBSTTree(keys, rootIdx, r + 1, j);
    return node;
}

struct TreeNode* constructOBST(int* keys, int keysSize, int* freq, int freqSize) {
    int n = keysSize;
    int cost[105][105];
    int rootIdx[105][105];
    int w[105][105];

    for (int i = 0; i < n; i++) {
        w[i][i] = freq[i];
        cost[i][i] = freq[i];
        rootIdx[i][i] = i;
        for (int j = i + 1; j < n; j++) {
            w[i][j] = w[i][j - 1] + freq[j];
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + w[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    rootIdx[i][j] = r;
                }
            }
        }
    }

    return buildOBSTTree(keys, rootIdx, 0, n - 1);
}