#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumRootToLeaf(TreeNode* root, int currentVal = 0) {
    if (!root) return 0;
    currentVal = (currentVal << 1) | root->val;
    if (!root->left && !root->right) return currentVal;
    return sumRootToLeaf(root->left, currentVal) + sumRootToLeaf(root->right, currentVal);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
