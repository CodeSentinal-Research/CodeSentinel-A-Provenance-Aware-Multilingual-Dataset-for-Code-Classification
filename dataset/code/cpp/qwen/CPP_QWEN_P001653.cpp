#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long long maxPathSumHelper(TreeNode* root, long long& maxSum) {
    if (!root) return 0;
    long long leftMax = max(0LL, maxPathSumHelper(root->left, maxSum));
    long long rightMax = max(0LL, maxPathSumHelper(root->right, maxSum));
    maxSum = max(maxSum, root->val + leftMax + rightMax);
    return root->val + max(leftMax, rightMax);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
