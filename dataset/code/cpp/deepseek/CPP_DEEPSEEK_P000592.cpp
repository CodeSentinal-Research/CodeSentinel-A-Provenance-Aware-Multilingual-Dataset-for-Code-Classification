#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode preHead(0);
    preHead.next = head;
    ListNode* prev = &preHead;
    ListNode* curr = head;
    while(curr != NULL) {
        if(curr->val == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
       
        }
    }
    return preHead.next;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);

    head->next = two;
    two->next = three;
    three->next = four;

    removeElements(head, 2);

    return 0;
}

In this code, we first create a dummy node as a header for our linked list. This is necessary because we need to remove the header node from our list. The preHead.next is used to start from the first node of the list after we have made changes.

We first initialize prev and curr to point to the dummy node and the head of the list, respectively.

We enter a while loop that continues until we have checked all nodes. In each iteration of the loop, we check if the value of the current node is equal to the value we are looking for.

If it is, we skip it by changing the next pointer of the previous node to skip over the current node and then delete the current node.

If it is not, we move on to the next node.

The last line in the main function is just a driver function to test the code. It creates a linked list 1 -> 2 -> 3 -> 4, removes the value of 2, and prints the resulting list.