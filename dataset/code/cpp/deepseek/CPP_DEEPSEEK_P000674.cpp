Here is a simple C++ code snippet for your problem. The code defines a Node structure and a Linked List class, then rearranges the list into a zigzag order.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rearrange() {
        Node* current = head;
        Node* end = head;
        bool fromLeft = true;

        while (end->next) {
            end = end->next;
        }

        while (current != end && current != end->next) {
            if (fromLeft) {
                if (current == head) {
                    head = current->next;
                } else {
                    Node* nextNode = current->next;
                    current->next = current->next->next;
                    nextNode->next = end->next;
                    end->next = nextNode;
                }
            } else {
                if (current == head) {
                    head = current->next;
                } else {
                    Node* prevNode = current->next;
                    current->next = current->next->next;
                    prevNode->next = end->next;
                    end->next = prevNode;
                }
            }

            current = current->next;
            fromLeft = !fromLeft;
        }
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++) {
        list.push(i);
    }

    list.print();
    list.rearrange();
    list.print();

    return 0;
}

This code first creates a linked list with the numbers 1 to 5, then prints the list and rearranges it into a zigzag order.