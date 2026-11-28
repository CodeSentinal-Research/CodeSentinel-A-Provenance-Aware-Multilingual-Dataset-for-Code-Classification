Here is the C++ code for the problem:

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* segregateEvenOdd(ListNode* head) {
    ListNode* evenStart = NULL;
    ListNode* evenEnd = NULL;
    ListNode* oddStart = NULL;
    ListNode* oddEnd = NULL;
    
    while(head) {
        if((head->val & 1) == 0) {
            if(evenStart == NULL) {
                evenStart = head;
                evenEnd = head;
            } else {
                evenEnd->next = head;
                evenEnd = head;
            }
        } else {
            if(oddStart == NULL) {
                oddStart = head;
                oddEnd = head;
            } else {
                oddEnd->next = head;
                oddEnd = head;
            }
        }
        head = head->next;
    }
    
    if(evenStart == NULL || oddStart == NULL)
        return head;
    
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    
    return evenStart;
}

In this code, we traverse the given linked list. For each node, we check if it's even or odd by performing a bitwise AND operation with 1 (which is `true` for even and `false` for odd). If it's even, we append it to the `evenEnd` node. If it's odd, we append it to the `oddEnd` node. We also update `evenEnd` and `oddEnd` pointers when we append a node.

Finally, we link the two lists and return `evenStart` as the new head of the list.