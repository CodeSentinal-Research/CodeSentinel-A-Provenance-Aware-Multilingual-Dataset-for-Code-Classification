Here is a C++ solution that creates a height-balanced Binary Search Tree from a sorted doubly linked list.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int val) : val(val), prev(NULL), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

ListNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* slow = head, *fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}

void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;

    TreeNode* root = sortedListToBST(head);
    levelOrder(root);

    return 0;
}

This program first constructs a height-balanced BST from a sorted doubly linked list. The `sortedListToBST` function uses a slow and fast pointer to find the middle of the list. Then, it recursively constructs left and right subtrees.

The `levelOrder` function prints the values of the BST level by level.

In the `main` function, a sorted doubly linked list is created, and the BST is constructed from it. The BST is then printed level by level.