Here is the C++ code that solves the Josephus problem using a circular linked list:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;
    if (*head_ref != NULL) {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    }
    else {
        new_node->next = new_node;
    }
}

int josephus(Node* head, int k) {
    Node* current = head;
    while (head != current) {
        for (int i = 1; i < k; i++)
            current = current->next;
        Node* temp = current;
        current = current->next;
        delete(temp);
        head = current;
    }
    return head->data;
}

int main() {
    Node* head = NULL;
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the interval: ";
    cin >> k;
    for (int i = 1; i <= n; i++)
        append(&head, i);
    cout << "The survivor is: " << josephus(head, k);
    return 0;
}

This code first declares a struct Node to represent a node in the linked list. Then it defines a function to append a new node to the end of the list. It also defines a function to simulate the process of eliminating people in the Josephus problem using the circular linked list. The main function reads the number of people and the interval, then it appends the people to the list, and finally it simulates the process and prints the survivor.