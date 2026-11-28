#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct PerfBSTResult {
    bool isBST, isPerf;
    int height, minV, maxV;
};

struct PerfBSTResult dfsPerfBST(struct TreeNode* node, int* maxSize) {
    if (node == NULL) {
        struct PerfBSTResult res = {true, true, 0, INT_MAX, INT_MIN};
        return res;
    }

    struct PerfBSTResult l = dfsPerfBST(node->left, maxSize);
    struct PerfBSTResult r = dfsPerfBST(node->right, maxSize);

    bool isBST = l.isBST && r.isBST && l.maxV < node->val && node->val < r.minV;
    int minV = MIN(l.minV, node->val);
    int maxV = MAX(r.maxV, node->val);

    if (isBST && l.isPerf && r.isPerf && l.height == r.height) {
        int curH = l.height + 1;
        int size = (1 << curH) - 1;
        *maxSize = MAX(*maxSize, size);
        struct PerfBSTResult res = {true, true, curH, minV, maxV};
        return res;
    }

    struct PerfBSTResult res = {false, false, 0, 0, 0};
    return res;
}

int largestPerfectBSTSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsPerfBST(root, &maxSize);
    return maxSize;
}