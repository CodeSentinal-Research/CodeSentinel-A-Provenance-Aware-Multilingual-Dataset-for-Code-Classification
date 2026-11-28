Here is the code:

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int val) : val(val), next(NULL), random(NULL) {}
};

Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;
    unordered_map<Node*, Node*> originalToCopy;
    Node* current = head;

    Node* newHead = new Node(head->val);
    originalToCopy[head] = newHead;
    current = head->next;

    while (current != NULL) {
        if (originalToCopy.find(current) != originalToCopy.end()) {
            newHead->next = originalToCopy[current]->next;
            newHead->random = originalToCopy[current]->random;
            newHead = newHead->next;
        } else {
            Node* newNode = new Node(current->val);
            originalToCopy[current] = newNode;
            newHead->next = newNode;
            newHead = newHead->next;
       
            current = current->next;
        }
    }
    return newHead;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;
    head->next->next = new Node(3);
    head->next->random = new Node(3);
    head->next->next->random = head;

    Node* newHead = copyRandomList(head);

    Node* newCurrent = newHead;
    while (newCurrent != NULL) {
        cout << newCurrent->val << " ";
        newCurrent = newCurrent->next;
    }
    cout << endl;

    return 0;
}
This code creates a new copy of each node in the original list, using a map to track the original nodes and the copied nodes. It uses a while loop to traverse through the original list and copy each node, based on whether the copied node already exists in the map.

This solution has a time complexity of O(n), where n is the number of nodes in the original list, and a space complexity of O(n) for the map.