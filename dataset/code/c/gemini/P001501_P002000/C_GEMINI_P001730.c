#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderClist(struct TreeNode* node, struct TreeNode** head, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderClist(node->left, head, prev);
    if (*head == NULL) {
        *head = node;
    } else {
        (*prev)->right = node;
        node->left = *prev;
    }
    *prev = node;
    inorderClist(node->right, head, prev);
}

struct TreeNode* bTreeToClist(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *head = NULL, *prev = NULL;
    inorderClist(root, &head, &prev);
    prev->right = head;
    head->left = prev;
    return head;
}