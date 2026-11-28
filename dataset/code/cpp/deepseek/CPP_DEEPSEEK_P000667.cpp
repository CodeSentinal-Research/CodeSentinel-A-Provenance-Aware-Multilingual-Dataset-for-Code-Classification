#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

struct CircularDeque {
    Node* head;
    Node* tail;
    int size;

    CircularDeque() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~CircularDeque() {
        while (head) {
            Node* old = head;
            head = head->next;
            delete old;
        }
    }

    void insertFront(int value) {
        Node* node = new Node;
        node->value = value;
        if (head == nullptr) {
            node->next = node->prev = node;
            head = tail = node;
        } else {
            node->next = head;
            node->prev = tail;
            tail->prev = node;
            head->prev = node;
            head = node;
        }
        size++;
    }

    void insertLast(int value) {
        Node* node = new Node;
        node->value = value;
        if (tail == nullptr) {
            node->next = node->prev = node;
            tail = head = node;
        } else {
            node->prev = tail;
            node->next = head;
            head->prev = node;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void deleteFront() {
        if (head == nullptr) return;
        Node* old = head;
        head = head->next;
        head->prev = tail;
        tail->next = old->next;
        delete old;
        size--;
    }

    void deleteLast() {
        if (tail == nullptr) return;
        Node* old = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = old->prev;
        delete old;
        size--;
    }

    int getFront() {
        return head->value;
    }

    int getRear() {
        return tail->value;
    }

    bool isEmpty() {
        return size == 0;
    }

    int size() {
        return size;
    }
};

void processQueries(CircularDeque& deque, int q) {
    for (int i = 0; i < q; i++) {
        int op, value;
        cin >> op >> value;
        if (op == 1) {
            deque.insertFront(value);
        } else if (op == 2) {
            deque.insertLast(value);
        } else if (op == 3) {
            deque.deleteFront();
        } else if (op == 4) {
            deque.deleteLast();
        }
        cout << "Front: " << deque.getFront() << ", Rear: " << deque.getRear() << ", Size: " << deque.size() << ", Empty: " << (deque.isEmpty() ? "Yes" : "No") << endl;
    }
}

int main() {
    int q;
    cin >> q;
    CircularDeque deque;
    processQueries(deque, q);
    return 0;
}
This C++ code defines a CircularDeque class using a doubly linked list. The class includes methods for inserting elements at both ends (insertFront and insertLast), removing elements from both ends (deleteFront and deleteLast), accessing the front and rear elements, checking if the deque is empty, and returning the size of the deque. In the main function, the user is prompted to input the number of queries, and for each query, the user is prompted to input the operation (1, 2, 3, or 4) and the value to be inserted or deleted. The deque is processed according to the operations and the results are printed.