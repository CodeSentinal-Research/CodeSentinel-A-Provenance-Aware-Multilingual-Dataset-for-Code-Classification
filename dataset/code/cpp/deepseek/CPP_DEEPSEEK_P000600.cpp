Here's the code:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next ? odd->next->next : NULL;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    head = oddEvenList(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

This code first checks if the head of the list is NULL, and if it is, returns the head of the list. Then, it creates two pointers: odd and even, which point to the head of the even and odd groups.

Then, it enters a while loop that continues until it has processed all the nodes in the list (i.e., until even and even->next are not NULL). Within the loop, it reassigns the next pointer of the odd node to the next node in the odd group (odd->next = even->next), then it reassigns the next pointer of the even node to the next node in the next odd group (even->next = odd->next ? odd->next->next : NULL), and finally, it reassigns the next pointer of the odd node to the next node in the odd group (odd->next = evenHead).

Finally, it reassigns the next pointer of the last odd node to the head of the even group (odd->next = evenHead).

This solution does not require any additional space complexity as it modifies the input linked list in-place. The time complexity is O(n) as it iterates through all the nodes once.