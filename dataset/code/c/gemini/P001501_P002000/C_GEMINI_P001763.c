#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfsUnival(struct TreeNode* node, int* count) {
    if (node == NULL) return true;
    bool l = dfsUnival(node->left, count);
    bool r = dfsUnival(node->right, count);

    if (l && r) {
        if ((node->left == NULL || node->left->val == node->val) && 
            (node->right == NULL || node->right->val == node->val)) {
            (*count)++;
            return true;
        }
    }
    return false;
}

int countUnivalSubtrees(struct TreeNode* root) {
    int count = 0;
    dfsUnival(root, &count);
    return count;
}