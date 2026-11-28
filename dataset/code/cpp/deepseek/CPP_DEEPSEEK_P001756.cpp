#include <iostream>
#include <queue>
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

Node* createTree(string s, int &i) {
    if (s[i] == '-') {
        i++;
        return NULL;
    }
    Node* node = newNode(s[i++]);
    node->left = createTree(s, i);
    node->right = createTree(s, i);
    return node;
}

bool checkLeafSiblings(Node* root) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if ((root->left != NULL && root->right != NULL) &&
        (checkLeafSiblings(root->left) && checkLeafSiblings(root->right))) {
        return true;
    }
    return false;
}

int main() {
    string s;
    getline(cin, s);
    int n = stoi(s);
    getline(cin, s);
    int i = 0;
    Node* root = createTree(s, i);
    if (checkLeafSiblings(root)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}