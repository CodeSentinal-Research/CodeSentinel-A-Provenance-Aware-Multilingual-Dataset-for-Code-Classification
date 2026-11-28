#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        root = newNode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool isFoldable(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 == NULL || root2 == NULL) {
        return false;
    }
    return (isFoldable(root1->left, root2->right) &&
            isFoldable(root1->right, root2->left));
}

int main() {
    int n;
    cin >> n;
    Node* root1 = NULL;
    Node* root2 = NULL;
    while(n--) {
        int data;
        cin >> data;
        root1 = insert(root1, data);
    }
    cin >> n;
    while(n--) {
        int data;
        cin >> data;
        root2 = insert(root2, data);
    }
    if(isFoldable(root1, root2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}