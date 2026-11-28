#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEvenOddTree(struct TreeNode* root) {
    if (root == NULL) return true;
    struct TreeNode** q = (struct TreeNode**)malloc(100005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int level = 0;

    while (tail > head) {
        int size = tail - head;
        int prev = -1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            if (level % 2 == 0) {
                if (node->val % 2 == 0 || (prev != -1 && node->val <= prev)) {
                    free(q);
                    return false;
                }
            } else {
                if (node->val % 2 != 0 || (prev != -1 && node->val >= prev)) {
                    free(q);
                    return false;
                }
            }
            prev = node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        level++;
    }
    free(q);
    return true;
}