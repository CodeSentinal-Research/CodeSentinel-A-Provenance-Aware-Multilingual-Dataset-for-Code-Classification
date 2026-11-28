#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int listCycleLength(ListNode *head) {
    if (head == NULL) {
        return 0;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow = head;
    int cycleLength = 0;
    
    while (slow != fast) {
        slow = slow->next;
        cycleLength++;
    }
    
    return cycleLength;
}