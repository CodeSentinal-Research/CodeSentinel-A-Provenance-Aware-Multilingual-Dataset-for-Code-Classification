#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct UnivalResult {
    bool isUnival;
    int size;
};

struct UnivalResult dfsUnivalSubtree(struct TreeNode* node, int* maxSize) {
    if (node == NULL) {
        struct UnivalResult res = {true, 0};
        return res;
    }
    struct UnivalResult l = dfsUnivalSubtree(node->left, maxSize);
    struct UnivalResult r = dfsUnivalSubtree(node->right, maxSize);

    if (l.isUnival && r.isUnival) {
        if ((node->left == NULL || node->left->val == node->val) &&
            (node->right == NULL || node->right->val == node->val)) {
            int curSize = l.size + r.size + 1;
            *maxSize = MAX(*maxSize, curSize);
            struct UnivalResult res = {true, curSize};
            return res;
        }
    }
    struct UnivalResult res = {false, 0};
    return res;
}

int largestUnivalueSubtree(struct TreeNode* root) {
    int maxSize = 0;
    dfsUnivalSubtree(root, &maxSize);
    return maxSize;
}