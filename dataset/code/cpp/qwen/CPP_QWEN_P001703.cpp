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

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void dfs(TreeNode* node, int minVal, int maxVal, int& maxDiff) {
    if (!node) return;
    maxDiff = max(maxDiff, abs(node->val - minVal));
    maxDiff = max(maxDiff, abs(node->val - maxVal));
    
    minVal = min(minVal, node->val);
    maxVal = max(maxVal, node->val);
    
    dfs(node->left, minVal, maxVal, maxDiff);
    dfs(node->right, minVal, maxVal, maxDiff);
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    int maxDiff = 0;
    if (root) {
        dfs(root, root->val, root->val, maxDiff);
    }
    cout << maxDiff << endl;
    
    return 0;
}
