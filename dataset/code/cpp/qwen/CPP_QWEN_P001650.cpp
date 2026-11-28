#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(inorder, postorder, inStart, inRoot - 1, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTree(inorder, postorder, inRoot + 1, inEnd, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i) inMap[inorder[i]] = i;
    
    TreeNode* root = buildTree(inorder, postorder, 0, n - 1, 0, n - 1, inMap);
    cout << "Tree constructed" << endl;
    return 0;
}
