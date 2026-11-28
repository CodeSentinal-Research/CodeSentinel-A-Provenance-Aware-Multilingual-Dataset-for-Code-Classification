Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeConsecutiveDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* current = head;
    while (current != NULL && current->next != NULL) {
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    head = removeConsecutiveDuplicates(head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

In this code, we are creating a linked list in the main function and calling the `removeConsecutiveDuplicates` function to remove the consecutive duplicate nodes. The modified linked list is then printed out.