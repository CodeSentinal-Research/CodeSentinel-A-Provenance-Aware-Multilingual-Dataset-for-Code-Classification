#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderCheckRot(struct TreeNode* node, long long* prev, bool* possible) {
    if (node == NULL || !(*possible)) return;
    inorderCheckRot(node->left, prev, possible);
    if (node->val <= *prev) {
        *possible = false;
        return;
    }
    *prev = node->val;
    inorderCheckRot(node->right, prev, possible);
}

bool canBeBSTByRotations(struct TreeNode* root) {
    long long prev = LLONG_MIN;
    bool possible = true;
    inorderCheckRot(root, &prev, &possible);
    return possible;
}