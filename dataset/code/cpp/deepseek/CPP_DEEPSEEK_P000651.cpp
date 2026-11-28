#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* deleteLastNode(Node* head) {
    if(head == NULL) return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL) {
        fast = fast->next;
        if(fast->next == NULL) {
            slow->next = NULL;
            break;
        }
        slow = slow->next;
    }
    return head;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    Node* second = new Node();
    second->data = 2;
    head->next = second;
    Node* third = new Node();
    third->data = 3;
    second->next = third;
    Node* fourth = new Node();
    fourth->data = 4;
    third->next = fourth;
    Node* fifth = new Node();
    fifth->data = 5;
    fourth->next = fifth;
    fifth->next = NULL;

    head = deleteLastNode(head);

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}

In this code, we first create a linked list. Then, we call the `deleteLastNode` function with the head of the list as the argument, and print the result. The output of this code will be "1 2 3 4".