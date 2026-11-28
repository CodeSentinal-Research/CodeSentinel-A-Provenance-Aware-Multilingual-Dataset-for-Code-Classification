#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestUnivalueHelper(TreeNode* root, int& maxLen) {
    if (!root) return 0;
    int l = longestUnivalueHelper(root->left, maxLen);
    int r = longestUnivalueHelper(root->right, maxLen);
    
    int leftArrow = 0, rightArrow = 0;
    if (root->left && root->left->val == root->val) leftArrow = l + 1;
    if (root->right && root->right->val == root->val) rightArrow = r + 1;
    
    maxLen = max(maxLen, leftArrow + rightArrow);
    return max(leftArrow, rightArrow);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
