#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* splitListToParts(ListNode* head, int k) {
    ListNode* current = head;
    int n = 0;
    
    while (current) {
        current = current->next;
        n++;
    }
    
    int w = n / k;
    int r = n % k;
    
    ListNode* prev = NULL, *newHead = NULL;
    for (int i = 0; head && i < k; i++, r--) {
        ListNode* part = new ListNode(head->val);
        if (!prev) prev = part;
        else {
            prev->next = part;
            prev = part;
        }
        head = head->next;
        if (i == w) {
            if (r > 0) {
                newHead = prev;
                r++;
            } else {
                newHead = part;
                r = k - i;
            }
        }
    }
    return newHead;
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
    ListNode* result = splitListToParts(head, k);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
This code firstly creates a list node. Then, in the main function, it creates a linked list with five nodes. Then it calls the `splitListToParts` function with the list and k as parameters. The function returns the head of the new linked list which is then printed out.