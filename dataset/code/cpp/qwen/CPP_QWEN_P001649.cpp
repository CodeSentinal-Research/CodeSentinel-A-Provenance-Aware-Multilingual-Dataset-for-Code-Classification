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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, inMap);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i) inMap[inorder[i]] = i;
    
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1, inMap);
    cout << "Tree constructed" << endl;
    return 0;
}
