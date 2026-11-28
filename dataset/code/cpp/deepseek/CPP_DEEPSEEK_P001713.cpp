#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

TreeNode* constructTree(int pre[], int size, int *preIndex) {
    if (*preIndex >= size || pre[*preIndex] == -1) {
        return NULL;
    }

    TreeNode* root = newNode(pre[(*preIndex)++]);

    root->left = constructTree(pre, size, preIndex);
    root->right = constructTree(pre, size, preIndex);

    return root;
}

TreeNode* construct(int pre[], int size) {
    int preIndex = 0;
    return constructTree(pre, size, &preIndex);
}

void printInorder(TreeNode* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

void printPostorder(TreeNode* node) {
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->val << " ";
}

int main() {
    int pre[] = {10, 30, 40, 60, 70, 80, 90, -1, -1, 20, 50, -1, -1, 15, -1, -1};
    int size = sizeof(pre) / sizeof(pre[0]);

    TreeNode* root = construct(pre, size);

    cout << "Inorder traversal of the constructed tree is : ";
    printInorder(root);
    cout << endl;

    cout << "Postorder traversal of the constructed tree is : ";
    printPostorder(root);

    return 0;
}
This C++ code will construct a binary tree from a given preorder traversal array and print the inorder and postorder traversals of the constructed tree. The nodes are connected by a parent-child relationship.