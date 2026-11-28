#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* middle = slow->next;
    slow->next = NULL;
    ListNode* left = head, *right = middle->next;
    middle->next = NULL;
    
    left = sortList(left);
    right = sortList(right);
    
    ListNode* mergedHead = new ListNode(0);
    ListNode* p = mergedHead;
    while (left && right) {
        if (left->val < right->val) {
            p->next = left;
            left = left->next;
        } else {
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }
    if (left) {
        p->next = left;
    } else {
        p->next = right;
    }
    
    return mergedHead->next;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);
    
    head = sortList(head);
    
    for (ListNode* p = head; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    
    return 0;
}
This code first finds the middle of the linked list by using two pointers (slow and fast) moving at different speeds. Then, it separates the list into two halves. The left half is sorted by calling the sortList function recursively, while the right half is also sorted. Finally, the sorted lists are merged in ascending order.