#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class Iterator {
private:
    stack<Node*> s;
    void pushAll(Node* node) {
        while (node) {
            s.push(node);
            node = node->right;
        }
    }

public:
    Iterator(Node* root) {
        pushAll(root);
    }

    bool hasPrev() {
        return !s.empty();
    }

    Node* prev() {
        Node* node = s.top();
        s.pop();
        pushAll(node->left);
        return node;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    Iterator iterator(root);

    while (iterator.hasPrev()) {
        Node* node = iterator.prev();
        cout << node->data << " ";
    }

    return 0;
}

In this code, a binary search tree is created and an iterator is created for it. The iterator can retrieve the next largest element in amortized O(1) time using O(h) auxiliary space. The main function demonstrates this by printing the next largest element from the iterator.