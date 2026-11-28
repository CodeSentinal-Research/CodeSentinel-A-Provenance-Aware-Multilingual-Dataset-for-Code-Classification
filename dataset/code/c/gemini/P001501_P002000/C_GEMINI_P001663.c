#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isCompleteTree(struct TreeNode* root) {
    if (root == NULL) return true;
    struct TreeNode** q = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    bool sawNull = false;

    while (tail > head) {
        struct TreeNode* node = q[head++];
        if (node == NULL) {
            sawNull = true;
        } else {
            if (sawNull) {
                free(q);
                return false;
            }
            q[tail++] = node->left;
            q[tail++] = node->right;
        }
    }
    free(q);
    return true;
}