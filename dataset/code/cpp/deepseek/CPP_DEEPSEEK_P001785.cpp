Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxIndepSetSize(Node *root)
    {
        if (!root)
            return 0;
        int size[2] = {0};
        getSize(root, size);
        return max(size[0], size[1]);
    }

private:
    int getSize(Node *node, int size[])
    {
        if (!node)
        {
            size[0] = size[1] = 0;
            return 0;
        }
        int leftSize[2], rightSize[2];
        getSize(node->left, leftSize);
        getSize(node->right, rightSize);
        size[0] = max(leftSize[0] + rightSize[1], max(leftSize[1], rightSize[0] + leftSize[1]));
        size[1] = leftSize[1] + rightSize[1] + node->data;
        return size[0];
    }
};

int main()
{
    int N;
    cin >> N;
    Node *nodes[N];
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        nodes[i] = new Node(data);
    }
    for (int i = 0; i < N - 1; i++)
    {
        nodes[i]->left = nodes[i + 1];
        nodes[i]->right = nodes[i + 2];
    }
    if (N == 2)
        nodes[1]->left = nodes[0];
    Solution solution;
    cout << solution.maxIndepSetSize(nodes[0]) << endl;
    return 0;
}
This code first reads the number of nodes, then reads the data for each node. It then constructs a binary tree from the node data. Finally, it uses the `maxIndepSetSize` function of the `Solution` class to find the size of the maximum independent set in the binary tree. The size of an independent set is the maximum sum of weights of nodes in a tree. The function `maxIndepSetSize` returns the maximum of the two sizes.