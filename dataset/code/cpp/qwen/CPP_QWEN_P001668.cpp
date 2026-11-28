#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, TreeNode*> subtreeWithAllDeepest(TreeNode* root) {
    if (!root) return {0, NULL};
    auto left = subtreeWithAllDeepest(root->left);
    auto right = subtreeWithAllDeepest(root->right);
    if (left.first > right.first) return {left.first + 1, left.second};
    if (right.first > left.first) return {right.first + 1, right.second};
    return {left.first + 1, root};
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
