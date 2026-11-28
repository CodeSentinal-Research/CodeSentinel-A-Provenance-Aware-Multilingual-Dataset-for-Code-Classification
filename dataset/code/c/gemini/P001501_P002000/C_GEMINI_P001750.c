#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minNodesLevel(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    int minNodes = INT_MAX, minLevel = 1, curLevel = 1;

    while (tail > head) {
        int size = tail - head;
        if (size < minNodes) {
            minNodes = size;
            minLevel = curLevel;
        }
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        curLevel++;
    }
    free(q);
    return minLevel;
}