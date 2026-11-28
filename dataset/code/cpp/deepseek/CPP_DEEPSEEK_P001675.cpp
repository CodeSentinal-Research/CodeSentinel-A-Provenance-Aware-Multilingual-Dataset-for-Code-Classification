#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(Node* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = buildTree(root->left, data);
    }
    else
    {
        root->right = buildTree(root->right, data);
    }
    return root;
}

void diagonalTraversal(Node* root, bool leftToRight)
{
    if (root == NULL) return;

    if (leftToRight)
    {
        cout << root->data << " ";
        diagonalTraversal(root->right, !leftToRight);
        diagonalTraversal(root->left, !leftToRight);
    }
    else
    {
        cout << root->data << " ";
        diagonalTraversal(root->left, !leftToRight);
        diagonalTraversal(root->right, !leftToRight);
    }
}

int main()
{
    Node* root = NULL;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = buildTree(root, data);
    }

    diagonalTraversal(root, true);

    return 0;
}

In the above code, `newNode` function is used to create a new node. `buildTree` function is used to build the binary tree from the input. The `diagonalTraversal` function is used to print the diagonal traversal. It uses a queue to perform level order traversal. It uses a boolean variable `leftToRight` to decide whether we need to print the nodes from right to left or left to right based on the condition.