#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct CompleteInfo {
    bool isComp, isPerf;
    int height, size;
};

struct CompleteInfo dfsComplete(struct TreeNode* node, int* maxSize) {
    if (node == NULL) {
        struct CompleteInfo info = {true, true, 0, 0};
        return info;
    }

    struct CompleteInfo l = dfsComplete(node->left, maxSize);
    struct CompleteInfo r = dfsComplete(node->right, maxSize);

    int curSize = l.size + r.size + 1;

    if (l.isPerf && r.isComp && l.height == r.height) {
        *maxSize = MAX(*maxSize, curSize);
        struct CompleteInfo info = {true, r.isPerf, l.height + 1, curSize};
        return info;
    }

    if (l.isComp && r.isPerf && l.height == r.height + 1) {
        *maxSize = MAX(*maxSize, curSize);
        struct CompleteInfo info = {true, false, l.height + 1, curSize};
        return info;
    }

    struct CompleteInfo info = {false, false, 0, 0};
    return info;
}

int largestCompleteSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsComplete(root, &maxSize);
    return maxSize;
}