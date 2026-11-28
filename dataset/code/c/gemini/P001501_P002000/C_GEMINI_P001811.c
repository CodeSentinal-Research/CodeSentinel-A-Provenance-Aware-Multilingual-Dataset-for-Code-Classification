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

struct BSTSubResult {
    bool isBST;
    int size, minVal, maxVal;
};

struct BSTSubResult dfsBSTSub(struct TreeNode* node, int* maxSize) {
    if (node == NULL) {
        struct BSTSubResult res = {true, 0, INT_MAX, INT_MIN};
        return res;
    }

    struct BSTSubResult l = dfsBSTSub(node->left, maxSize);
    struct BSTSubResult r = dfsBSTSub(node->right, maxSize);

    if (l.isBST && r.isBST && l.maxVal < node->val && node->val < r.minVal) {
        int curSize = l.size + r.size + 1;
        *maxSize = MAX(*maxSize, curSize);
        struct BSTSubResult res = {true, curSize, MIN(l.minVal, node->val), MAX(r.maxVal, node->val)};
        return res;
    }

    struct BSTSubResult res = {false, 0, 0, 0};
    return res;
}

int largestBSTSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsBSTSub(root, &maxSize);
    return maxSize;
}