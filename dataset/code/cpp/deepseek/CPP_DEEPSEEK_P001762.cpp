#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node
{
    int value;
    Node *left, *right;

    Node(int value) : value(value), left(NULL), right(NULL) {}
};

Node *buildTree(vector<int> &values, int start, int end)
{
    if (start > end)
        return NULL;

    int minValue = INT_MAX;
    int idx = start;

    for (int i = start; i <= end; i++)
    {
        if (values[i] < minValue)
        {
            minValue = values[i];
            idx = i;
        }
    }

    Node *root = new Node(minValue);
    root->left = buildTree(values, start, idx - 1);
    root->right = buildTree(values, idx + 1, end);

    return root;
}

pair<int, int> getMinSum(Node *root)
{
    if (root == NULL)
        return {0, 0};

    int leftSum = root->left ? getMinSum(root->left).first : 0;
    int rightSum = root->right ? getMinSum(root->right).first : 0;

    int sum = leftSum + rightSum + root->value;

    return {sum, max(leftSum, rightSum) + root->value};
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    Node *root = buildTree(values, 0, n - 1);

    pair<int, int> result = getMinSum(root);

    cout << result.second << endl;

    return 0;
}