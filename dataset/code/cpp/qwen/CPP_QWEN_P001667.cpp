#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void maxAncestorDiff(TreeNode* root, int minVal, int maxVal, int& result) {
    if (!root) return;
    result = max(result, max(abs(root->val - minVal), abs(root->val - maxVal)));
    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);
    maxAncestorDiff(root->left, minVal, maxVal, result);
    maxAncestorDiff(root->right, minVal, maxVal, result);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
