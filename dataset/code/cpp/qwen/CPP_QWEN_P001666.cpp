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

int longestZigzag(TreeNode* root, bool goLeft, int len) {
    if (!root) return len;
    if (goLeft) {
        return max(longestZigzag(root->left, false, len + 1), longestZigzag(root->right, true, 1));
    } else {
        return max(longestZigzag(root->right, true, len + 1), longestZigzag(root->left, false, 1));
    }
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
