Here is the C++ code for the problem:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* newNode = new Node();
    if(!newNode) {
        cout << "Memory error" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}

Node* sortedMerge(Node* l1, Node* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }

    Node* result = NULL;

    if (l1->data < l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    Node* current = result;

    while (l1 != result && l2 != result) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != result) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return result;
}

void printList(Node* n) {
    if (n == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* start = n;
    do {
        cout << n->data << " ";
        n = n->next;
    } while (n != start);

    cout << endl;
}

int main() {
    Node* l1 = newNode(10);
    l1->next = newNode(20);
    l1->next->next = newNode(30);

    Node* l2 = newNode(5);
    l2->next = newNode(15);
    l2->next->next = newNode(25);

    Node* result = sortedMerge(l1, l2);

    printList(result);

    return 0;
}

In this code, two linked lists are created and merged using the `sortedMerge` function. The `sortedMerge` function takes two circular sorted linked lists and merge them. The `newNode` function is used to create a new node in the heap. The `printList` function is used to print the merged list.