#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderCDLL(struct TreeNode* node, struct TreeNode** head, struct TreeNode** prev) {
    if (node == NULL) return;
    inorderCDLL(node->left, head, prev);
    if (*head == NULL) {
        *head = node;
    } else {
        (*prev)->right = node;
        node->left = *prev;
    }
    *prev = node;
    inorderCDLL(node->right, head, prev);
}

struct TreeNode* treeToDoublyList(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *head = NULL, *prev = NULL;
    inorderCDLL(root, &head, &prev);
    prev->right = head;
    head->left = prev;
    return head;
}