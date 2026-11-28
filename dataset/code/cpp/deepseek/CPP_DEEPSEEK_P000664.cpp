#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* deleteAlternateNodes(Node* head) {
    if (!head || !head->next) return head;

    Node* current = head->next;
    Node* nextNode = current->next;

    while (current && nextNode) {
        delete current;
        current = nextNode;
        if (current->next) {
            nextNode = current->next->next;
        } else {
            nextNode = nullptr;
        }
    }

    head->next = nextNode;
    return head;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    Node* second = new Node();
    second->data = 2;
    Node* third = new Node();
    third->data = 3;
    Node* fourth = new Node();
    fourth->data = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = deleteAlternateNodes(head);

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
This code first initializes a linked list with nodes. Then, it calls the `deleteAlternateNodes` function to delete the alternate nodes from the linked list. The function loops through the linked list and deletes each alternate node by setting the next pointer of the previous node to the next node after the current node. Finally, it returns the head of the modified linked list.

In the main function, we initialize a linked list with nodes and then call the `deleteAlternateNodes` function. The result is printed out.