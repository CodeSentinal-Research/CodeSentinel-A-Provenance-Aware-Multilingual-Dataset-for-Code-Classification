Here's a simplified version of the code for your problem. The code creates a binary tree from the input and deletes the leaf nodes with the given value.

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* buildTree(queue<int>& q) {
    int x = q.front(); q.pop();
    if (x == -1) return NULL;
    Node* root = new Node(x);
    root->left = buildTree(q);
    root->right = buildTree(q);
    return root;
}

void deleteLeaves(Node* root, int target) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (root->data != target) return;
        delete root;
        root = NULL;
        return;
    }
    deleteLeaves(root->left, target);
    deleteLeaves(root->right, target);
}

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        q.push(x);
    }
    Node* root = buildTree(q);
    int target; cin >> target;
    deleteLeaves(root, target);
    return 0;
}

In the code above, the `buildTree` function builds a binary tree from a level-order traversal of the input, using the queue `q`. Each node is created using the `new Node(x)` constructor, and its left and right children are created by calling `buildTree(q)` recursively.

The `deleteLeaves` function deletes the leaf nodes with the given target value. It does this by checking if the current node is a leaf (i.e., if its left and right children are NULL), and if so, checks if its value is the target. If both conditions are met, the node is deleted. If the current node is not a leaf, the function is called recursively on its left and right children.

In the main function, the code reads the number of nodes `n` and constructs the binary tree using `buildTree(q)`. Then, it reads the target value `target` and deletes the leaf nodes with the given target from the tree.