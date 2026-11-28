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

struct Info {
    long long sum;
    bool isBST;
    int minVal;
    int maxVal;
};

Info maxBSTSumHelper(TreeNode* root, long long& maxSum) {
    if (!root) return {0, true, INT_MAX, INT_MIN};
    
    Info left = maxBSTSumHelper(root->left, maxSum);
    Info right = maxBSTSumHelper(root->right, maxSum);
    
    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        long long currSum = root->val + left.sum + right.sum;
        maxSum = max(maxSum, currSum);
        return {currSum, true, min(root->val, left.minVal), max(root->val, right.maxVal)};
    }
    
    return {0, false, 0, 0};
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
