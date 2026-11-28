#include <iostream>
#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findMin(ListNode* head) {
    if(head == NULL) return INT_MAX; 
    int minVal = head->val;
    ListNode* current = head;
    while(current != NULL) {
        if(current->val < minVal) minVal = current->val;
        current = current->next;
    }
    return minVal;
}

int main() {
    return 0;
}