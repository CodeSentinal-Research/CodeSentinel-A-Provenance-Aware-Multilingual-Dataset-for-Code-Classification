Here's the C++ code for the problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseFirstKNodes(ListNode* head, int k) {
    if (head == NULL || k <= 0)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy, *end = dummy;
    
    while (k-- > 0) {
        if (end->next == NULL)
            return dummy->next;
        end = end->next;
    }
    
    while (pre != end) {
        ListNode* next = pre->next;
        pre->next = end->next;
        end->next = pre;
        pre = pre->next;
    }
    
    return dummy->next;
}

This code uses a dummy node to simulate the head of the linked list. The dummy node's next pointer is set to the head of the original list. Then, the code enters a while loop that continues until it reaches the position where the last node is set, i.e., when the end pointer points to the node right after the last node that needs to be reversed. Inside this loop, the code updates the pointer for the end pointer.

After that, the code enters a while loop that continues until the end of the list has been reached. Inside this loop, the code swaps the next pointer of the current node with the next pointer of the end node, effectively reversing the node.

Finally, the code returns the new head of the list, which is now the next node of the dummy node.