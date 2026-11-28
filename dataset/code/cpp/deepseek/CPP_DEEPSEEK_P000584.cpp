Here is a C++ solution that removes the n-th node from the end of a linked list:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* slow = &dummy, *fast = &dummy;
    fast = slow;
    for(int i = 0; i < n + 1; i++)
        fast = fast->next;
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
}

int main() {
    int size, val, n;
    cout << "Enter size of the linked list: ";
    cin >> size;
    cout << "Enter the value of the nth node to be removed: ";
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for(int i = 0; i < size; i++) {
        cout << "Enter value for node " << (i + 1) << " (or -1 to indicate end): ";
        cin >> val;
        ListNode* node = new ListNode(val);
        if(i == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    head = removeNthFromEnd(head, n);
    return 0;
}

In this code, we first declare a `ListNode` struct for the linked list. We then define a function `removeNthFromEnd` that takes in the head of the list and the nth node to be removed. This function uses two pointers, `slow` and `fast`, to find the node to be removed. The `fast` pointer moves `n` steps at a time, while `slow` moves one step at a time. When `fast` reaches the end of the list, `slow` will be at the node to be removed.

In the main function, we first prompt the user for the size of the linked list, the value of the nth node to be removed, and the values of the nodes in the list. We create a new list from the given values and remove the nth node from the end of the list.