Here is the code. This problem is about checking if a given binary tree is a valid inorder threaded binary tree. Inorder threaded binary tree is a binary tree in which left child is threaded as 'L' and right child is threaded as 'R', and each node in the tree has a pointer pointing to the inorder predecessor and successor.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* link_left;
    Node* link_right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = temp->link_left = temp->link_right = NULL;
    return temp;
}

Node* buildTree(int data, Node* root, int &index,
                vector<bool> &visited, vector<int> &inorder)
{
    if (data == -1)
    {
        visited[index] = true;
        return NULL;
    }

    Node* temp = newNode(data);

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        if (visited[index])
        {
            temp->link_left = root;
            root->link_right = temp;
            visited[index] = false;
        }
        else
        {
            temp->link_right = root;
            root->link_left = temp;
       
        }
    }
    visited[index] = true;
    index++;

    temp->left = buildTree(inorder[index], root, index, visited, inorder);
    temp->right = buildTree(inorder[index], root, index, visited, inorder);

    return temp;
}

int isMirror(Node* a, Node* b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return ((a->data == b->data) &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

bool isThreaded(Node* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    if (root->left == NULL || root->right == NULL)
        return false;

    return (isMirror(root->left, root->right) &&
            isThreaded(root->left->link_right) &&
            isThreaded(root->right->link_left));
}

int main()
{
    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    Node* root = NULL;
    int index = 0;

    root = buildTree(inorder[0], root, index, visited, inorder);

    if (isThreaded(root))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
This program reads the inorder traversal of the binary tree and then checks if the binary tree is a threaded inorder binary tree. If it is, it prints "YES", otherwise it prints "NO". The binary tree is represented by an integer array, where each integer represents the data of a node in the binary tree. If the integer is -1, it represents a null child for that node.