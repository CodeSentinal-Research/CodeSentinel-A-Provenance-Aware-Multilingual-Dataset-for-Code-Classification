#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* cur = dummy;
    while(head != NULL && head->next != NULL) {
        ListNode* first = head;
        ListNode* second = head->next;
        
        cur->next = second;
        cur = first;
        first->next = second->next;
        second->next = first;
        
        head = first->next;
        if(head != NULL)
            head = head->next;
    }
    
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    head = swapPairs(head);

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}