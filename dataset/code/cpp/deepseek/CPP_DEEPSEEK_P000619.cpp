Here's the code:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) {
        return NULL;
    }
    
    ListNode* slow = head, *fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (slow->next == head) {
        head = head->next;
    } else {
        slow->next = slow->next->next;
    }
    
    return head;
}

int main() {
    return 0;
}

This code first checks if the list has at least two nodes. If not, it returns an empty list. Then it creates two pointers, `slow` and `fast`, and initializes them to the head of the list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time. This way, the `fast` pointer will reach the end of the list, and the `slow` pointer will be at the middle of the list.

If the list has an odd number of nodes, the slow pointer will be at the node right before the middle node. If the list has an even number of nodes, the slow pointer will be at the node right after the middle node.

Then it swaps the next pointer of the node that slow pointer is pointing to with the next pointer of the node right after the node slow is pointing to, effectively deleting the middle node.

Please note that this code assumes that the input linked list is already sorted. If the list is not sorted, you will need to add additional logic to sort the list before deleting the middle node.