#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isSorted(ListNode* head) {
    if (!head) return true;
    
    ListNode* current = head;
    while (current->next) {
        if (current->val > current->next->val) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    
    head->next = second;
    second->next = third;
    
    if (isSorted(head)) {
        cout << "The linked list is sorted" << endl;
    } else {
        cout << "The linked list is not sorted" << endl;
    }
    
    return 0;
}