Here is the C++ code for the problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* lessHead = new ListNode(0);
    ListNode* lessTail = lessHead;
    ListNode* equalHead = new ListNode(0);
    ListNode* equalTail = equalHead;
    ListNode* greaterHead = new ListNode(0);
    ListNode* greaterTail = greaterHead;
    
    while(head != NULL){
        if(head->val < x){
            lessTail->next = head;
            lessTail = lessTail->next;
        }
        else if(head->val == x){
            equalTail->next = head;
            equalTail = equalTail->next;
        }
        else{
            greaterTail->next = head;
            greaterTail = greaterTail->next;
        }
        head = head->next;
    }
    
    lessTail->next = equalHead->next;
    equalTail->next = greaterHead->next;
    
    return lessHead->next;
}

int main() {
    return 0;
}

This code creates three dummy heads for nodes with values less than x, equal to x and greater than x respectively. It then iterates through the original list, adding each node to the appropriate list and finally rearranges the pointers to form the final linked list.