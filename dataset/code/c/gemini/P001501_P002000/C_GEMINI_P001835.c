#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct DeadFreeResult {
    bool isFree;
    int size;
};

struct DeadFreeResult dfsDeadFree(struct TreeNode* node, int low, int high, int* maxSize) {
    if (node == NULL) {
        struct DeadFreeResult res = {true, 0};
        return res;
    }
    if (low == high) {
        struct DeadFreeResult res = {false, 0};
        return res;
    }

    struct DeadFreeResult l = dfsDeadFree(node->left, low, node->val - 1, maxSize);
    struct DeadFreeResult r = dfsDeadFree(node->right, node->val + 1, high, maxSize);

    if (l.isFree && r.isFree) {
        int curSize = l.size + r.size + 1;
        *maxSize = MAX(*maxSize, curSize);
        struct DeadFreeResult res = {true, curSize};
        return res;
    }

    struct DeadFreeResult res = {false, 0};
    return res;
}

int largestDeadEndFreeSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsDeadFree(root, 1, INT_MAX, &maxSize);
    return maxSize;
}