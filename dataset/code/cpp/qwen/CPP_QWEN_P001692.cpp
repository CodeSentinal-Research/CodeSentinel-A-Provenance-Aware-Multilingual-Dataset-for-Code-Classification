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

int longestConsecutiveHelper(TreeNode* root, int& maxLen) {
    if (!root) return 0;
    int l = longestConsecutiveHelper(root->left, maxLen);
    int r = longestConsecutiveHelper(root->right, maxLen);
    
    int len = 1;
    if (root->left && root->left->val == root->val + 1) len = max(len, l + 1);
    if (root->right && root->right->val == root->val + 1) len = max(len, r + 1);
    
    maxLen = max(maxLen, len);
    return len;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
