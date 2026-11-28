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

struct CompBSTResult {
    bool isBST, isComp, isPerf;
    int height, size, minV, maxV;
};

struct CompBSTResult dfsCompBST(struct TreeNode* node, int* maxSize) {
    if (node == NULL) {
        struct CompBSTResult res = {true, true, true, 0, 0, INT_MAX, INT_MIN};
        return res;
    }

    struct CompBSTResult l = dfsCompBST(node->left, maxSize);
    struct CompBSTResult r = dfsCompBST(node->right, maxSize);

    bool isBST = l.isBST && r.isBST && l.maxV < node->val && node->val < r.minV;
    int curSz = l.size + r.size + 1;
    int minV = MIN(l.minV, node->val);
    int maxV = MAX(r.maxV, node->val);

    if (isBST) {
        if (l.isPerf && r.isComp && l.height == r.height) {
            *maxSize = MAX(*maxSize, curSz);
            struct CompBSTResult res = {true, true, r.isPerf, l.height + 1, curSz, minV, maxV};
            return res;
        }
        if (l.isComp && r.isPerf && l.height == r.height + 1) {
            *maxSize = MAX(*maxSize, curSz);
            struct CompBSTResult res = {true, true, false, l.height + 1, curSz, minV, maxV};
            return res;
        }
    }

    struct CompBSTResult res = {false, false, false, 0, 0, 0, 0};
    return res;
}

int largestCompleteBSTSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsCompBST(root, &maxSize);
    return maxSize;
}