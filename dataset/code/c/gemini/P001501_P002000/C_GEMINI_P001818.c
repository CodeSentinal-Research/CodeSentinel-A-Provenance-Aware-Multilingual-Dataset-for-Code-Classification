#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lcaMultipleBST(struct TreeNode* root, struct TreeNode** nodes, int nodesSize) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < nodesSize; i++) {
        minVal = MIN(minVal, nodes[i]->val);
        maxVal = MAX(maxVal, nodes[i]->val);
    }

    struct TreeNode* cur = root;
    while (cur) {
        if (maxVal < cur->val) {
            cur = cur->left;
        } else if (minVal > cur->val) {
            cur = cur->right;
        } else {
            return cur;
        }
    }
    return NULL;
}