#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isIdentical(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data)
            return false;
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == NULL && current2 == NULL)
        return true;

    return false;
}

int main() {
    Node* head1 = new Node();
    Node* head2 = new Node();



    if (isIdentical(head1, head2))
        cout << "Both lists are identical\n";
    else
        cout << "Lists are not identical\n";

    return 0;
}

The code defines a linked list node with `data` and a pointer to the next node. Then the `isIdentical` function compares the `data` of two linked lists. It traverses both linked lists until it finds a node where the `data` is not equal in both lists. If all the nodes are traversed and found nodes with unequal `data`, it returns false. Otherwise, it returns true.

In the `main` function, it creates two linked lists and calls the `isIdentical` function to compare the two linked lists. It prints the result.