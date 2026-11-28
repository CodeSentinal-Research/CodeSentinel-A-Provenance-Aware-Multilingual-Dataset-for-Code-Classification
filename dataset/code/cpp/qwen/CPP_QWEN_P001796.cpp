#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildBSTFromPreorder(vector<int>& preorder, int& idx, int minVal, int maxVal) {
    if (idx >= preorder.size()) return NULL;
    int val = preorder[idx];
    if (val < minVal || val > maxVal) return NULL;
    
    TreeNode* root = new TreeNode(val);
    idx++;
    root->left = buildBSTFromPreorder(preorder, idx, minVal, val);
    root->right = buildBSTFromPreorder(preorder, idx, val, maxVal);
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    
    int idx = 0;
    TreeNode* root = buildBSTFromPreorder(preorder, idx, INT_MIN, INT_MAX);
    printLevelOrder(root);
    
    return 0;
}
