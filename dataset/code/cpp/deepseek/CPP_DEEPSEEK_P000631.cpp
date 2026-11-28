#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool searchElement(ListNode* head, int target) {
  ListNode* current = head;

  while (current != NULL) {
    if (current->val == target) {
      return true;
    }
    current = current->next;
  }

  return false;
}

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  int target = 3;

  bool result = searchElement(head, target);

  if (result) {
    cout << "Element found in the list" << endl;
  } else {
    cout << "Element not found in the list" << endl;
  }

  return 0;
}