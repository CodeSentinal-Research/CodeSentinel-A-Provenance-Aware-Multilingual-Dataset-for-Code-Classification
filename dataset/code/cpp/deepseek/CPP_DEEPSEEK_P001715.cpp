Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* buildTreeUtil(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd) {
    if (preStart > preEnd) return NULL;

    Node* node = newNode(pre[preStart]);

    if (preStart == preEnd) return node;

    int iIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (in[i] == pre[preStart]) {
            iIndex = i;
            break;
        }
    }

    node->left = buildTreeUtil(pre, preStart + 1, preStart + iIndex - inStart, in, inStart, iIndex - 1);
    node->right = buildTreeUtil(pre, preStart + iIndex - inStart + 1, preEnd, in, iIndex + 1, inEnd);

    return node;
}

void printFullNodes(Node* node) {
    if (node == NULL) return;

    if (node->left != NULL && node->right != NULL) {
        cout << node->data << " ";
    }

    printFullNodes(node->left);
    printFullNodes(node->right);
}

int main() {
    int pre[] = {10, 30, 40, 60, 70, 80, 90};
    int in[] = {30, 60, 70, 40, 10, 80, 90};

    int n = sizeof(pre) / sizeof(pre[0]);

    Node* root = buildTreeUtil(pre, 0, n - 1, in, 0, n - 1);

    printFullNodes(root);

    return 0;
}
This program first builds the binary tree from the preorder and inorder arrays. It then calls a function that prints all the nodes that have both left and right children. The function `printFullNodes` does the printing.