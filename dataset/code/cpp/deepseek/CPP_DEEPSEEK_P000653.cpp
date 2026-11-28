#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevNode = &dummy;
    ListNode* node1 = head;
    ListNode* node2 = head->next;
    
    while(node1 && node2) {
        prevNode->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        
        prevNode = node1;
        node1 = node1->next;
        node2 = node1->next;
    }
    
    return dummy.next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    ListNode* newHead = swapPairs(head);
    
    while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    
    return 0;
}

This code first creates a dummy node and sets the next pointer of dummy node to head of input linked list. Then it initializes prevNode and node1 as head and next node of head respectively. node2 is the next node of node1 and then it swaps the nodes. The next node of node1 and node2 is then set as next node of prevNode. The process continues until node1 is null (which indicates the end of the linked list). The dummy node's next pointer is returned as the new head of the linked list.