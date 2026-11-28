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

pair<int, int> robHelper(TreeNode* root) {
    if (!root) return {0, 0};
    auto left = robHelper(root->left);
    auto right = robHelper(root->right);
    
    int rob = root->val + left.second + right.second;
    int notRob = max(left.first, left.second) + max(right.first, right.second);
    
    return {rob, notRob};
}

int rob(TreeNode* root) {
    auto res = robHelper(root);
    return max(res.first, res.second);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
