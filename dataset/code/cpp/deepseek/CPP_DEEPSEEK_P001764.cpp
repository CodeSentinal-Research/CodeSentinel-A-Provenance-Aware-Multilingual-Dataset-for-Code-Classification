#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int largestUnivalSubtree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftSize = largestUnivalSubtree(root->left);
    int rightSize = largestUnivalSubtree(root->right);
    
    int leftUnivalSize = 0, rightUnivalSize = 0;
    if (root->left != nullptr && root->left->val == root->val) {
        leftUnivalSize = leftSize + 1;
    }
    if (root->right != nullptr && root->right->val == root->val) {
        rightUnivalSize = rightSize + 1;
    }
    
    return max(max(leftUnivalSize, rightUnivalSize), leftSize + rightSize);
}

int main() {
    int n;
    cin >> n;

    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);
    TreeNode* last = root;
    for (int i = 1; i < n; ++i) {
        cin >> val;
        last->right = new TreeNode(val);
        last = last->right;
    }
    last->right = nullptr; 

    cout << largestUnivalSubtree(root) << endl;

    return 0;
}