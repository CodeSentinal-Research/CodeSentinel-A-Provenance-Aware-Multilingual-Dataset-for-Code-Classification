#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Result {
    int depth;
    struct TreeNode* node;
};

struct Result dfsDeepest(struct TreeNode* node) {
    if (node == NULL) {
        struct Result res = {0, NULL};
        return res;
    }
    struct Result l = dfsDeepest(node->left);
    struct Result r = dfsDeepest(node->right);
    if (l.depth == r.depth) {
        struct Result res = {l.depth + 1, node};
        return res;
    } else if (l.depth > r.depth) {
        struct Result res = {l.depth + 1, l.node};
        return res;
    } else {
        struct Result res = {r.depth + 1, r.node};
        return res;
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return dfsDeepest(root).node;
}