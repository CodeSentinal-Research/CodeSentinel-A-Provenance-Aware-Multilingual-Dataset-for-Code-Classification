#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& arr, int* index, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int maxElement = arr[*index];
    Node* root = new Node(maxElement);

    (*index)++;

    if (start == end)
    {
        return root;
    }

    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] > maxElement)
        {
            break;
        }
    }

    root->left = buildTree(arr, index, start, i - 1);
    root->right = buildTree(arr, index, i, end);

    return root;
}

int widthOfBinaryTree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<pair<Node*, int>> q;
    q.push({ root, 0 });

    int curr_level = 0, prev_level = 0, ans = 0;

    while (!q.empty())
    {
        int count = q.size();
        prev_level = curr_level;
        curr_level++;

        while (count--)
        {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == prev_level)
            {
                ans = max(ans, level - curr_level + 1);
            }
            else
            {
                curr_level = level;
            }

            if (node->left)
            {
                q.push({ node->left, level + 1 });
            }

            if (node->right)
            {
                q.push({ node->right, level + 1 });
            }
        }
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int index = 0;
    Node* root = buildTree(arr, &index, 0, N - 1);

    cout << widthOfBinaryTree(root);

    return 0;
}