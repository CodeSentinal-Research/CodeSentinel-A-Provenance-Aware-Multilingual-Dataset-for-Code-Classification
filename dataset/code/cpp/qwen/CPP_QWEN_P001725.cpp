#include <iostream>
#include <vector>
#include <queue>
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

int countPathsWithSumK(TreeNode* root, long long k) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        return root->val == k ? 1 : 0;
    }
    
    long long remaining = k - root->val;
    int leftCount = root->left ? countPathsWithSumK(root->left, remaining) : 0;
    int rightCount = root->right ? countPathsWithSumK(root->right, remaining) : 0;
    
    return leftCount + rightCount;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    cout << countPathsWithSumK(root, k) << endl;
    
    return 0;
}
