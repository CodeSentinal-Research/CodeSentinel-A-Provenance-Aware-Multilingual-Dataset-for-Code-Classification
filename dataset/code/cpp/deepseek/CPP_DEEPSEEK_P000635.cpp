#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseNodes(Node* head, int* groups, int size) {
    if (head == NULL) {
        return NULL;
    }

    int totalNodes = 0;
    Node* temp = head;
    while (temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    temp = head;
    while (totalNodes > 0) {
        if (totalNodes >= groups[size - 1]) {
            Node* nextNode = temp->next;
            for (int i = 0; i < groups[size - 1]; i++) {
                Node* nextNextNode = nextNode->next;
                nextNode->next = temp->next;
                temp->next = nextNode;
                nextNode = nextNextNode;
            }
        }
        totalNodes -= groups[size - 1];
        size--;
        if (totalNodes > 0) {
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int groups[] = {2, 1, 1, 1, 1};

    head = reverseNodes(head, groups, sizeof(groups) / sizeof(int));
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}