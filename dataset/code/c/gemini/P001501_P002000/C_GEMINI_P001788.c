#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* r = root->right;
            free(root);
            return r;
        }
        if (root->right == NULL) {
            struct TreeNode* l = root->left;
            free(root);
            return l;
        }
        struct TreeNode* minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }
    return root;
}