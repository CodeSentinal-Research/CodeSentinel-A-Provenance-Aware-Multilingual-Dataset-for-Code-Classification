#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *prev;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildListToBST(struct ListNode** cur, int count) {
    if (count <= 0) return NULL;
    struct TreeNode* left = buildListToBST(cur, count / 2);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = (*cur)->val;
    *cur = (*cur)->next;
    root->left = left;
    root->right = buildListToBST(cur, count - count / 2 - 1);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int count = 0;
    struct ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    struct ListNode* cur = head;
    return buildListToBST(&cur, count);
}