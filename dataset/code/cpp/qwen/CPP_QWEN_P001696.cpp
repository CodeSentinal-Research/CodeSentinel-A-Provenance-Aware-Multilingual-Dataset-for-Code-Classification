#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

void smallestStringFromLeaf(TreeNode* root, string current, string& result) {
    if (!root) return;
    current = root->val + current;
    if (!root->left && !root->right) {
        if (result.empty() || current < result) result = current;
        return;
    }
    smallestStringFromLeaf(root->left, current, result);
    smallestStringFromLeaf(root->right, current, result);
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
