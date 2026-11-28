#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

long long treeSumC(struct TreeNode* node, long long* allSums, int* idx) {
    if (node == NULL) return 0;
    long long cur = node->val + treeSumC(node->left, allSums, idx) + treeSumC(node->right, allSums, idx);
    allSums[(*idx)++] = cur;
    return cur;
}

int maxProduct(struct TreeNode* root) {
    long long allSums[50005];
    int idx = 0;
    long long total = treeSumC(root, allSums, &idx);
    long long maxProd = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < idx; i++) {
        long long s = allSums[i];
        maxProd = MAX(maxProd, s * (total - s));
    }
    return (int)(maxProd % MOD);
}