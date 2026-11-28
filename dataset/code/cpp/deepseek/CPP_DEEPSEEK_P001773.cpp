#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>& preorder) {
    if (preorder.empty()) return NULL;

    Node* root = new Node(preorder[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < preorder.size()) {
        if (preorder[i] == '#') {
            q.front()->left = NULL;
            q.pop();
        } else {
            Node* left = new Node(preorder[i]);
            q.front()->left = left;
            q.push(left);
        }

        i++;
        if (i < preorder.size() && preorder[i] == '#') {
            q.front()->right = NULL;
            q.pop();
        } else {
            Node* right = new Node(preorder[i]);
            q.front()->right = right;
            q.push(right);
        }
        q.pop();
    }

    return root;
}

void antiDiagonalSum(Node* root, int& sum, vector<int>& sums) {
    if (!root) return;

    sums[0] += root->data;

    if (!root->left && !root->right) {
        sum = max(sum, sums[0]);
    } else {
        if (root->left)
            antiDiagonalSum(root->left, sum, sums);
        if (root->right)
            antiDiagonalSum(root->right, sum, sums);
    }

    if (sums[0] == sum) {
        cout << sum;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> preorder(N);
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }

    Node* root = buildTree(preorder);
    int sum = 0;
    vector<int> sums(1, 0);
    antiDiagonalSum(root, sum, sums);

    return 0;
}
This code first builds the binary tree using the given preorder traversal. Then it calculates the sum of the nodes along every anti-diagonal and prints it if it's equal to the current sum.