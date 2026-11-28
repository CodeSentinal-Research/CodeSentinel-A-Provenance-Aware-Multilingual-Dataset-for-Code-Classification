#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertNode(struct TreeNode* node, int val) {
    if (node == NULL) {
        struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        n->val = val; n->left = NULL; n->right = NULL;
        return n;
    }
    if (val < node->val) node->left = insertNode(node->left, val);
    else node->right = insertNode(node->right, val);
    return node;
}

void addAllNodes(struct TreeNode* root1, struct TreeNode* node) {
    if (node == NULL) return;
    insertNode(root1, node->val);
    addAllNodes(root1, node->left);
    addAllNodes(root1, node->right);
}

struct TreeNode* joinBST(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;
    addAllNodes(root1, root2);
    return root1;
}