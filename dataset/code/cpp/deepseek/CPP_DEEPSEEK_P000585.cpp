#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }
    
    ListNode *slow = head, *fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *second = slow->next;
    slow->next = NULL;
    second->next = NULL;
    
    ListNode *prev = NULL, *curr = head, *nextTemp;
    
    while(curr != NULL) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    ListNode *l1 = prev, *l2 = second;
    
    while(l1 != NULL) {
        nextTemp = l2->next;
        l2->next = l1->next;
        l1->next = l2;
        l2 = l2->next->next;
        l1 = l1->next;
    }
    
    head = prev;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    reorderList(node1);
    
    ListNode *node = node1;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    
    return 0;
}
This code reorders the given linked list. The algorithm is based on the fast-slow pointer technique, where slow pointer is moving two steps at a time and fast pointer is moving one step at a time. This is done to find the middle of the list. Then we break the list into two halves and reverse the second half. After reordering, we merge the two halves.