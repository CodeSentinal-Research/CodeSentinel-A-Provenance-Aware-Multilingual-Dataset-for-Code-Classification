Here is the code:

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            ListNode *temp = current->next->next;
            delete current->next;
            current->next = temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(3);
    ListNode *fifth = new ListNode(4);
    ListNode *sixth = new ListNode(4);
    ListNode *seventh = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    head = deleteDuplicates(head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

This program first creates a linked list with the values 1, 2, 3, 3, 4, 4, 5. It then calls the `deleteDuplicates` function with the head of the list as an argument. The `deleteDuplicates` function iterates through the list and removes nodes with the same value as the next node. It then returns the head of the modified list. The program then prints the elements of the modified list.