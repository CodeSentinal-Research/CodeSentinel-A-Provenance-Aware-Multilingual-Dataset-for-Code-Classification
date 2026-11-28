#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int val) : val(val), next(NULL) {}
};

Node* reverseEvenLengthGroup(Node* head) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* groupPrev = dummy;
    Node* groupHead = dummy;
    Node* groupTail = dummy;
    Node* current = head;
    int groupSize = 0;

    while (current) {
        for (int i = 0; i < groupSize && current; ++i, current = current->next) {
            if (groupTail->next && groupTail->next->next) {
                groupTail = groupTail->next->next;
            } else {
                groupTail = current;
            }
        }

        if (groupSize % 2 == 0) {
            groupPrev->next = groupTail->next;
            groupTail->next = groupHead->next;
            groupHead->next = groupTail;
            groupPrev = groupHead;
            groupHead = groupPrev->next;
        }

        groupSize = 0;
    }

    return dummy->next;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    head = reverseEvenLengthGroup(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}