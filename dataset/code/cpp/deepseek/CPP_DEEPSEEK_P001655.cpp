Here is the C++ code for converting a binary tree into a doubly linked list:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next, *prev;
    ListNode(int val) : val(val), next(NULL), prev(NULL) {}
};

void flatten(TreeNode* root, ListNode** head) {
    if (!root) return;

    flatten(root->left, head);

    flatten(root->right, head);

    root->left = *head;
    (*head)->next = root;

}

void printDLL(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    ListNode* head = nullptr;
    flatten(root, &head);

    printDLL(head);

    return 0;
}

This code first creates a binary tree and then converts it into a doubly linked list. The function `flatten` is the recursive function that flattens the binary tree into a doubly linked list. It updates the `head` pointer of the doubly linked list at each recursive call. The function `printDLL` prints the nodes of the doubly linked list from head to tail.