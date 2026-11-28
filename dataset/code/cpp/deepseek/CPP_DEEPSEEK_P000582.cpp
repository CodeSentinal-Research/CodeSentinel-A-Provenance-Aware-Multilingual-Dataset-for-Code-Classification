Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* current = head;
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            ListNode* temp = current->next->next;
            delete current->next;
            current->next = temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    ListNode* newHead = deleteDuplicates(head);

    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}

In this code, the `deleteDuplicates` function is implemented to remove duplicates from the sorted linked list. It iterates over the linked list and checks if the current node's value is the same as the next node's value. If they are the same, it skips the next node and deletes the current node. If they are not the same, it moves to the next node. This process is repeated until the end of the linked list.

In the `main` function, an example linked list is created with three nodes, and the `deleteDuplicates` function is called to remove the duplicates. The resulting linked list is printed.