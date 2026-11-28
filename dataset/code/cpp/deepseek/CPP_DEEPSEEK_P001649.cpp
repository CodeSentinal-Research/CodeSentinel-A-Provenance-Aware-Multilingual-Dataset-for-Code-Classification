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

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int startPre, int endPre, int startIn, int endIn) {
    if (startPre > endPre) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[startPre]);

    int rootIndexInorder = find(inorder.begin() + startIn, inorder.begin() + endIn, preorder[startPre]) - inorder.begin();

    int numLeftNodes = rootIndexInorder - startIn;

    root->left = buildTreeHelper(preorder, inorder, startPre + 1, startPre + numLeftNodes, startIn, rootIndexInorder - 1);
    root->right = buildTreeHelper(preorder, inorder, startPre + numLeftNodes + 1, endPre, rootIndexInorder + 1, endIn);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);

    return 0;
}