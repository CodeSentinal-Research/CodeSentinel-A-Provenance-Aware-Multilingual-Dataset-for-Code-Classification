#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class ListNode {
public:
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

class BSTNode {
public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    BSTNode* prevNode;

    BSTNode* flatten(BSTNode* root) {
        if (root == NULL) {
            return NULL;
        }

        flatten(root->left);

        root->left = prevNode;
        if (prevNode != NULL) {
            prevNode->right = root;
        }
        prevNode = root;

        flatten(root->right);
    }

    void flattenToDoublyLinkedList(BSTNode* root, ListNode** head) {
        if (root == NULL) {
            return;
        }

        BSTNode* right = root->right;

        flattenToDoublyLinkedList(root->left, head);

        root->left = *head;
        (*head)->next = root;

        if (*head != NULL) {
            (*head)->prev = root;
        }

        flattenToDoublyLinkedList(right, head);
    }

    void printDoublyLinkedList(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void convert(BSTNode* root) {
        ListNode* head = NULL;
        flattenToDoublyLinkedList(root, &head);
        printDoublyLinkedList(head);
    }

    Node* Solution::flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* prevNode = NULL;

        flatten(head, &prevNode);

        return prevNode;
    }

    void flatten(Node* head, Node** prev) {
        if (head == NULL) {
            return;
        }

        flatten(head->left, prev);

        head->left = *prev;
        if (*prev != NULL) {
            (*prev)->right = head;
        }

        flatten(head->right, prev);
    }

    void convert(Node* head) {
        Node* prevNode = NULL;
        flatten(head, &prevNode);
    }
};