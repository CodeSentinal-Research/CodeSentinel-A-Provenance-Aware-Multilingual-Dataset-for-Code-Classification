#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* current = head;
    while (current != nullptr) {
        ListNode* duplicate = current->next;
        while (duplicate != nullptr) {
            if (duplicate->val == current->val) {
                ListNode* temp = duplicate;
                duplicate = duplicate->next;
                delete temp;
                current->next = duplicate;
            } else {
                duplicate = duplicate->next;
            }
        }
        current = current->next;
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    ListNode* newHead = removeDuplicates(head);

    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}
This code defines a `ListNode` structure for the linked list. The `removeDuplicates` function is the function you will be implementing to remove duplicates from the linked list. It iterates through each node in the linked list and for each node, it iterates through its next node and deletes any node that is found to be a duplicate. The head of the list is updated to point to the new head of the list.

In the `main` function, a linked list is created with values 1, 2, 2, 3. The `removeDuplicates` function is called with the head of this list, and the resulting list is printed.