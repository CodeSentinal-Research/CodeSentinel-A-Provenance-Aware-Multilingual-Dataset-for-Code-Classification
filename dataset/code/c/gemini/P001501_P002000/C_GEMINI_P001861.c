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

struct DiamBSTResult {
    bool isBST;
    int size, height, diameter, minV, maxV;
};

struct DiamBSTResult dfsDiamBST(struct TreeNode* node, int* maxBSTSize, int* bestDiameter) {
    if (node == NULL) {
        struct DiamBSTResult res = {true, 0, 0, 0, INT_MAX, INT_MIN};
        return res;
    }

    struct DiamBSTResult l = dfsDiamBST(node->left, maxBSTSize, bestDiameter);
    struct DiamBSTResult r = dfsDiamBST(node->right, maxBSTSize, bestDiameter);

    if (l.isBST && r.isBST && l.maxV < node->val && node->val < r.minV) {
        int curSz = l.size + r.size + 1;
        int curH = 1 + MAX(l.height, r.height);
        int curD = MAX(l.height + r.height, MAX(l.diameter, r.diameter));

        if (curSz > *maxBSTSize) {
            *maxBSTSize = curSz;
            *bestDiameter = curD;
        }

        struct DiamBSTResult res = {true, curSz, curH, curD, MIN(l.minV, node->val), MAX(r.maxV, node->val)};
        return res;
    }

    struct DiamBSTResult res = {false, 0, 0, 0, 0, 0};
    return res;
}

int diameterOfLargestBST(struct TreeNode* root) {
    int maxBSTSize = 0, bestDiameter = 0;
    dfsDiamBST(root, &maxBSTSize, &bestDiameter);
    return bestDiameter;
}