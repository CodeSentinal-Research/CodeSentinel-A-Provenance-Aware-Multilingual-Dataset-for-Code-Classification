Here is a basic implementation of a queue that supports operations to insert elements at the front, middle, and back. The queue is implemented as a doubly linked list where each node contains a value and references to the next and previous nodes. 

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void pushFront(int x) {
        Node* node = new Node();
        node->val = x;
        node->next = head;
        node->prev = NULL;
        if (head != NULL) {
            head->prev = node;
        }
        head = node;
        if (tail == NULL) {
            tail = head;
        }
    }

    void pushMiddle(int x) {
        if (head == NULL) {
            pushFront(x);
            return;
        }
        Node* node = new Node();
        node->val = x;
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        node->next = slow->next;
        if (slow->next != NULL) {
            slow->next->prev = node;
        }
        slow->next = node;
        node->prev = slow;
        if (tail == slow) {
            tail = node;
        }
    }

    void pushBack(int x) {
        Node* node = new Node();
        node->val = x;
        node->prev = tail;
        node->next = NULL;
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
        if (head == NULL) {
            head = tail;
        }
    }

    int popFront() {
        if (head == NULL) {
            return -1;
        }
        int val = head->val;
        Node* node = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete node;
        if (head == NULL) {
            tail = NULL;
        }
        return val;
    }

    int popMiddle() {
        if (head == NULL) {
            return -1;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        int val = slow->val;
        Node* node = slow;
        if (node->prev != NULL) {
            node->prev->next = node->next;
        }
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
        if (head == slow) {
            head = node->next;
        }
        if (tail == slow) {
            tail = node->prev;
        }
        delete node;
        return val;
    }

    int popBack() {
        if (tail == NULL) {
            return -1;
        }
        int val = tail->val;
        Node* node = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        delete node;
        if (head == NULL) {
            tail = NULL;
        }
        return val;
    }
};

Please note that this code does not include input handling. You will need to add appropriate input handling based on your specific requirements.