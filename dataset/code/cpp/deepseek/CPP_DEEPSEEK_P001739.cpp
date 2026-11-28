Here is a simple C++ solution that creates a binary tree based on user input and then removes all leaf nodes.

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* buildTree()
{
    int data;
    cin >> data;
    if (data == -1) return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

Node* removeLeafNodes(Node* root)
{
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = buildTree();
    root = removeLeafNodes(root);
    levelOrder(root);
    return 0;
}

This program first builds a binary tree from user input. The `buildTree` function reads an integer (representing the node data) and recursively builds the binary tree.

Then, the `removeLeafNodes` function removes all leaf nodes from the binary tree. It first checks if the root node is NULL, then it deletes the root node and returns NULL. If the root node has left and right children, it recursively calls `removeLeafNodes` on the left and right children.

Finally, the `levelOrder` function prints the level order traversal of the modified binary tree.

The `main` function calls these functions and prints the resulting tree.