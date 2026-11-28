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

int maxSum(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = maxSum(root->left);
    int rightSum = maxSum(root->right);

    return max(root->val + max(leftSum, rightSum), max(leftSum, rightSum));
}

int main() {
    int N;
    cin >> N;
    vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        TreeNode* node = new TreeNode(val);
        nodes[i] = node;
    }
    for (int i = 0; i < N - 1; ++i) {
        TreeNode* parent = nodes[i / 2];
        if (i % 2 == 0) {
            parent->right = nodes[i + 1];
        } else {
            parent->left = nodes[i + 1];
        }
    }

    TreeNode* root = nodes[0];
    cout << maxSum(root) << endl;

    return 0;
}