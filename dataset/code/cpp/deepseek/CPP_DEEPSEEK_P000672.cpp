Here is the C++ code:

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthNode(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p = &dummy;
    ListNode* q = &dummy;
    for (int x = 1; p && x < n; ++x) {
        p = p->next;
    }
    if (!p) {
        return head;
    }
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    return dummy.next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tmp = head;
    for (int i = 2; i <= 10; ++i) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }

    int n;
    cout << "Enter the N to remove the Nth node: ";
    cin >> n;

    head = removeNthNode(head, n);

    for (tmp = head; tmp; tmp = tmp->next) {
        cout << tmp->val << ' ';
    }
    cout << '\n';

    return 0;
}

In this code, we first create a dummy node with value 0 and set the next pointer of the dummy node to the head of the original list. Then, we use two pointers p and q to traverse the list. p is moved n steps from the head, and q is moved one step from p. After that, q's next pointer is set to the node next to the node it points to, effectively skipping the n-th node in the list.