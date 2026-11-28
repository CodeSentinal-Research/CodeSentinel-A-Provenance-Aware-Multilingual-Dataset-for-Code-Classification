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

TreeNode* buildBSTFromPostorder(vector<int>& postorder, int& idx, int minVal, int maxVal) {
    if (idx < 0) return NULL;
    int val = postorder[idx];
    if (val < minVal || val > maxVal) return NULL;
    
    TreeNode* root = new TreeNode(val);
    idx--;
    root->right = buildBSTFromPostorder(postorder, idx, val, maxVal);
    root->left = buildBSTFromPostorder(postorder, idx, minVal, val);
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
    vector<int> postorder(n);
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    
    int idx = n - 1;
    TreeNode* root = buildBSTFromPostorder(postorder, idx, INT_MIN, INT_MAX);
    printLevelOrder(root);
    
    return 0;
}
