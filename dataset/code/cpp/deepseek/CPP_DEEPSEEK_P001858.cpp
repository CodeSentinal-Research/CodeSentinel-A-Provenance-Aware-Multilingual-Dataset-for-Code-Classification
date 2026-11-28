#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, unordered_map<int, int>& idx) {
    if (start > end) return NULL;
    TreeNode* node = new TreeNode(postorder[postorder.size()-1]);
    int root = idx[node->val];
    postorder.pop_back();
    node->right = buildTree(inorder, postorder, root+1, end, idx);
    node->left = buildTree(inorder, postorder, start, root-1, idx);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++) {
        idx[inorder[i]] = i;
    }
    return buildTree(inorder, postorder, 0, inorder.size()-1, idx);
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    TreeNode* root = buildTree(inorder, postorder);
    return 0;
}