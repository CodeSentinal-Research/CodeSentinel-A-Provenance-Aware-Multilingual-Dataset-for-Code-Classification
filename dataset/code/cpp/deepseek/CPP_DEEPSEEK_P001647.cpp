#include <iostream>
#include <queue>
#include <map>

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

void bottom_view(Node *root)
{
    if (root == NULL)
        return;

    map<int, int> nodes_at_current_depth;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        Node *node = current.first;
        int depth = current.second;

        nodes_at_current_depth[depth] = node->data;

        if (node->left)
            q.push({node->left, depth + 1});

        if (node->right)
            q.push({node->right, depth + 1});
    }

    for (auto it = nodes_at_current_depth.begin(); it != nodes_at_current_depth.end(); ++it)
        cout << it->second << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    bottom_view(root);

    return 0;
}