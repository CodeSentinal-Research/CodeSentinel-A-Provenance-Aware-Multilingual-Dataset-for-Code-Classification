#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& nodes, int start, int end) {
    if (start > end) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[start]);
    int mid = start + (end - start) / 2;
    root->left = createTree(nodes, start, mid);
    root->right = createTree(nodes, mid + 1, end);
    return root;
}

void sumUp(TreeNode* root, int& sum) {
    if (root == NULL) {
        return;
    }
    sum += root->val;
    root->val = sum;
    sumUp(root->left, sum);
    sumUp(root->right, sum);
}

void transformTree(TreeNode* root) {
    int sum = 0;
    sumUp(root, sum);
}

int main() {
    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; i++) {
        cin >> nodes[i];
    }
    TreeNode* root = createTree(nodes, 0, N - 1);
    transformTree(root);
    return 0;
}