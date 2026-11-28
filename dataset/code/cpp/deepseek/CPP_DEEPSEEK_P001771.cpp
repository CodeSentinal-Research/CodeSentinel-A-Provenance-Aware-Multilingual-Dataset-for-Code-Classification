#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int> &arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);
    return root;
}

map<int, int> verticalSum(Node* root) {
    map<int, int> result;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        Node* node = q.front().first;
        int col = q.front().second;
        q.pop();
        if (node != NULL) {
            result[col] += node->val;
            q.push({node->left, col - 1});
            q.push({node->right, col + 1});
        }
    }
    return result;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    Node* root = buildTree(arr, 0);
    map<int, int> result = verticalSum(root);
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
    return 0;
}
This C++ solution uses the Breadth First Search (BFS) algorithm to traverse the binary tree. The BFS algorithm visits nodes in a level by level order. In this solution, we use a queue to hold nodes and their corresponding column index. We map the column index to the sum of node values in that column.

In the main function, we first read the number of nodes and the node values. Then we build the binary tree using the given node values and root. We then call the verticalSum function to get the sum of node values in each column and print them out.