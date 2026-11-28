#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isCompleteBinaryTree(Node* root) {
    if (root == NULL) {
        return true;
    }

    queue<Node*> q;
    bool isLeaf = false;

    q.push(root);

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->left != NULL) {
            if (isLeaf) {
                return false;
            }
            q.push(node->left);
        } else {
            isLeaf = true;
        }

        if (node->right != NULL) {
            if (isLeaf) {
                return false;
            }
            q.push(node->right);
        } else {
            isLeaf = false;
        }
    }

    return true;
}

int main() {
    return 0;
}