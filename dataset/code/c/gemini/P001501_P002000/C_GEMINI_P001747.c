#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxLeafLevel(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    int maxLeaves = -1, maxLevel = 1, curLevel = 1;

    while (tail > head) {
        int size = tail - head;
        int leafCount = 0;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            if (node->left == NULL && node->right == NULL) leafCount++;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        if (leafCount > maxLeaves) {
            maxLeaves = leafCount;
            maxLevel = curLevel;
        }
        curLevel++;
    }
    free(q);
    return maxLevel;
}