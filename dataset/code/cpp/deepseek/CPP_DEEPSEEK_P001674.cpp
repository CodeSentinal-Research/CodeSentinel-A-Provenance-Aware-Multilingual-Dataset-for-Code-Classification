Here is the C++ code for right view of a binary tree.

#include <iostream>
#include <queue>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printRightView(Node *root)
{
    if (root == NULL)
        return;
 
    queue<Node *> q;
    q.push(root);
 
    while (q.empty() == false)
    {
        Node *node = q.front();
        q.pop();
 
           node and push its children in the queue */
        if (q.empty() == true)
            cout << node->data << " ";
        else
            cout << "$ " << node->data << " ";
 
        if (node->right != NULL)
            q.push(node->right);
        if (node->left != NULL)
            q.push(node->left);
    }
}

Node* newNode(int data)
{
    Node *temp = new Node(data);
    return temp;
}

Node* buildTree(Node* root, int data)
{
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    else {
        if (data <= root->data)
            root->left = buildTree(root->left, data);
        else
            root->right = buildTree(root->right, data);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    int n, data;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter nodes data:\n";
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = buildTree(root, data);
    }
    printRightView(root);
    return 0;
}
In this code, a binary tree is created using the given nodes and then right view of the tree is printed. The nodes are created using an auxiliary function `buildTree` and then the right view of the tree is printed using the `printRightView` function.