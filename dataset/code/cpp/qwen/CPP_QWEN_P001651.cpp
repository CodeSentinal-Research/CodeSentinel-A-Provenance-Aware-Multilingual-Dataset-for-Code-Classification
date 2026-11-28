#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    if (preStart == preEnd) return root;
    
    int leftRootVal = preorder[preStart + 1];
    int leftRootPostIdx = postStart;
    while (postorder[leftRootPostIdx] != leftRootVal) leftRootPostIdx++;
    
    int leftSize = leftRootPostIdx - postStart + 1;
    
    root->left = buildTree(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftRootPostIdx);
    root->right = buildTree(preorder, postorder, preStart + leftSize + 1, preEnd, leftRootPostIdx + 1, postEnd - 1);
    
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    
    TreeNode* root = buildTree(preorder, postorder, 0, n - 1, 0, n - 1);
    cout << "Tree constructed" << endl;
    return 0;
}
