#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertAtBeginning(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = insertAtBeginning(head, 0);
    return 0;
}