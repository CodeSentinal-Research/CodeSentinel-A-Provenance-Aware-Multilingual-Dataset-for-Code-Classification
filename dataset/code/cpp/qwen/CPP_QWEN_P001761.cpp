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

long long getSubtreeSum(TreeNode* root, long long& maxSum, TreeNode*& maxRoot) {
    if (!root) return 0;
    
    long long leftSum = getSubtreeSum(root->left, maxSum, maxRoot);
    long long rightSum = getSubtreeSum(root->right, maxSum, maxRoot);
    
    long long total = root->val + leftSum + rightSum;
    if (total > maxSum) {
        maxSum = total;
        maxRoot = root;
    }
    
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    long long maxSum = LLONG_MIN;
    TreeNode* maxRoot = NULL;
    
    getSubtreeSum(root, maxSum, maxRoot);
    
    if (maxRoot) cout << maxRoot->val << endl;
    
    return 0;
}
