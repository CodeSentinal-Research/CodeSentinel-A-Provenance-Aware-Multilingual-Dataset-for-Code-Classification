#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left, * right, * parent;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

Node* insert(Node* node, int data) {
    if(node == NULL) return newNode(data);
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

Node* inorderSuccessor(Node* node) {
    if(node->right != NULL)
        return minValueNode(node->right);
    Node* successor = NULL;
    Node* ancestor = node->parent;
    while(ancestor != NULL && node == ancestor->right) {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    successor = ancestor;
    return successor;
}

void levelOrder(Node* node) {
    if(node == NULL) return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 25, 30, 7, 9, 28 };
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++)
        root = insert(root, keys[i]);
    Node* node = minValueNode(root);
    Node* successor = inorderSuccessor(node);
    if(successor == NULL)
        cout << "None\n";
    else
        cout << successor->data << "\n";
    return 0;
}
This code first creates a binary search tree from an array of keys. Then it finds the minimum value node in the tree and finds its inorder successor. If there is no inorder successor, it prints "None". Otherwise, it prints the inorder successor.