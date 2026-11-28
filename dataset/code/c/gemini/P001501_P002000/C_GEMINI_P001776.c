#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEveryLevelPalindromic(struct TreeNode* root) {
    if (root == NULL) return true;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (tail > head) {
        int size = tail - head;
        int* vals = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[head++];
            vals[i] = node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        for (int l = 0, r = size - 1; l < r; l++, r--) {
            if (vals[l] != vals[r]) {
                free(vals);
                free(q);
                return false;
            }
        }
        free(vals);
    }
    free(q);
    return true;
}