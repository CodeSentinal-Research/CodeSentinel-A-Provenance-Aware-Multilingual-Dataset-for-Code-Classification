#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;
int paths = 0;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* Node = new Node();
    if (!Node)
    {
        cout << "Memory error\n";
        return NULL;
    }
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

Node* construct(vector<int> &a, int start, int end)
{
    if (start > end)
        return NULL;

    Node *root = newNode(a[start]);

    int i;
    for (i = start + 1; i <= end; i++)
    {
        if (a[i] < root->data)
        {
            root->left = newNode(a[i]);
        }
        else
        {
            root->right = newNode(a[i]);
            break;
        }
    }

    if (i == end + 1)
        return root;

    root->left = construct(a, start + 1, i - 1);
    root->right = construct(a, i + 1, end);
    return root;
}

int countPseudoPalindromicPaths(Node* root)
{
    int counts[MAX] = {0};
    paths = 0;

    count(root, counts);

    return paths;
}

void count(Node* node, int counts[])
{
    if (!node)
        return;

    counts[node->data]++;

    if (!node->left && !node->right)
    {
        int odd = 0;

        for (int count : counts)
        {
            if (count & 1)
                odd++;
        }

        if (odd <= 1)
            paths++;
    }

    count(node->left, counts);
    count(node->right, counts);

    counts[node->data]--;
}

Node* construct(int arr[], int n)
{
    vector<int> a(arr, arr + n);
    return construct(a, 0, n - 1);
}

int main()
{
    int arr[] = {2, 5, 10, 4, 2, 3, 1, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr, n);

    cout << countPseudoPalindromicPaths(root);

    return 0;
}