#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool inorderRank(struct TreeNode* node, int key, int* rank) {
    if (node == NULL) return false;
    if (inorderRank(node->left, key, rank)) return true;
    if (node->val == key) {
        (*rank)++;
        return true;
    }
    if (node->val < key) (*rank)++;
    return inorderRank(node->right, key, rank);
}

int rankOfKey(struct TreeNode* root, int key) {
    int rank = 0;
    bool found = inorderRank(root, key, &rank);
    return found ? rank : -1;
}