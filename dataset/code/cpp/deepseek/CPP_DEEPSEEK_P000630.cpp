#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int kthToLastNode(ListNode* head, int k) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    for (int i = 0; i < k; i++) {
        if (p2 == nullptr) {
            return -1;
        }
        p2 = p2->next;
    }
    
    while (p2 != nullptr) {
        p2 = p2->next;
        p1 = p1->next;
    }
    
    return p1->val;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    int k = 3;
    cout << kthToLastNode(head, k) << endl;
    return 0;
}