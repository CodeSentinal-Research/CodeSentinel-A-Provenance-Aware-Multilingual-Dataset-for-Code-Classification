Here is a simple C++ code snippet that uses Floyd's Cycle Finding Algorithm to check if a linked list has a cycle. 

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = second;
    ListNode *third = new ListNode(3);
    second->next = third;
    third->next = head; 
    cout << hasCycle(head);
    return 0;
}

In this code, we use two pointers, slow and fast, to traverse the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle in the linked list, the fast pointer will eventually catch up to the slow pointer.