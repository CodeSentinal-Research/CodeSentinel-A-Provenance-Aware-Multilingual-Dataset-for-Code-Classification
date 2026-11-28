#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insertNode(Node** root, int data) {
    if(*root == NULL) {
    } else {
        if(data < (*root)->data) {
            insertNode(&((*root)->left), data);
        } else if(data > (*root)->data) {
            insertNode(&((*root)->right), data);
        }
    }
}

void countDistinctValues(Node* root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    unordered_set<int> distincts;
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        distincts.insert(node->data);
        if(node->left) {
            q.push(node->left);
        }
        if(node->right) {
            q.push(node->right);
        }
    }
    for(int val : distincts) {
        cout << val << endl;
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    while(n--) {
        int data;
        cin >> data;
        insertNode(&root, data);
    }
    countDistinctValues(root);
    return 0;
}