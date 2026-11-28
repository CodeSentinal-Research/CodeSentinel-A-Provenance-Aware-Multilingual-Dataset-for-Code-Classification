#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* buildTree(string arr) {
    if (arr == "null") return nullptr;
    Node* root = new Node(stoi(arr));
    queue<pair<Node*, string>> q;
    q.push({root, ""});
    while (!q.empty()) {
        auto nodePair = q.front();
        q.pop();
        string arrLeft = nodePair.second;
        string arrRight = "";
        if (arrLeft != "null") {
            Node* nodeLeft = new Node(stoi(arrLeft));
            nodePair.first->left = nodeLeft;
            q.push({nodeLeft, ""});
        }
        arrRight = arr.substr(arr.find("/") + 1);
        if (arrRight != "null") {
            Node* nodeRight = new Node(stoi(arrRight));
            nodePair.first->right = nodeRight;
            q.push({nodeRight, ""});
        }
    }
    return root;
}

void exterior(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    while (root->left || root->right) {
        if (root->left) {
            root = root->left;
        } else {
            root = root->right;
        }
        cout << root->data << " ";
    }
}

int main() {
    string arr;
    getline(cin, arr);
    int N = stoi(arr);
    getline(cin, arr);
    Node* root = buildTree(arr);
    exterior(root);
    return 0;
}
This C++ code firstly builds the binary tree from the input string. The buildTree function uses a level order traversal to create the binary tree and store the values in an array. It uses a queue to perform this operation. Then, the exterior function prints the exterior boundary of the binary tree in clockwise order.