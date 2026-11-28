#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderDLL(struct TreeNode* node, struct TreeNode** head, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderDLL(node->left, head, prev);
    if (*head == NULL) {
        *head = node;
    } else {
        (*prev)->right = node;
        node->left = *prev;
    }
    *prev = node;
    inorderDLL(node->right, head, prev);
}

struct TreeNode* treeToDoublyList(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *head = NULL, *prev = NULL;
    inorderDLL(root, &head, &prev);
    prev->right = head;
    head->left = prev;
    return head;
}