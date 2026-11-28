#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* bottom;
    Node(int x) : val(x), next(NULL), bottom(NULL) {}
};

Node* flatten(Node* head) {
    if (head == NULL) return head;
    
    Node* current = head;
    Node* nextNode = head->next;
    
    while (current != NULL) {
        if (nextNode == NULL) {
            current->next = NULL;
        } else {
            Node* nextNodeCopy = nextNode;
            while (nextNodeCopy->bottom != NULL) {
                nextNodeCopy = nextNodeCopy->bottom;
            }
            current->next = nextNodeCopy;
        }
        
        if (current->next != NULL) {
            Node* nextNextNode = current->next->next;
            current->next->bottom = current->bottom;
            current->bottom = current->next;
            current->next = nextNextNode;
        } else {
            current = current->next;
        }
    }
    
    return head->bottom;
}

This code defines a node structure for a linked list, and a function `flatten` that takes as input the head of a linked list and returns the head of the flattened linked list. The function uses a bottom pointer to track the end of each individual list, and a while loop to merge the lists together.

Please note that this solution assumes that the input linked list is already sorted. If it's not, you'll need to sort the lists before flattening them.